/*
** EPITECH PROJECT, 2022
** FTRACE
** File description:
** extract_functions.c
*/

#include "standards.h"
#include "list_func.h"

void manage_error(int argc, char **argv, vs_t *vs)
{
    vs->file = argv[1];
    vs->fd = open(vs->file, O_RDONLY);
    if (vs->fd < 0) {
        fprintf(stderr, "ERROR: Failed to open ELF binary file!\n");
        exit(84);
    }
    if (fstat(vs->fd, &vs->sb) < 0) {
        fprintf(stderr, "ERROR: Failed to retrieve file stats!\n");
        close(vs->fd);
        exit(84);
    }

    vs->data = mmap(NULL, vs->sb.st_size, PROT_READ, MAP_PRIVATE, vs->fd, 0);
    if (vs->data == MAP_FAILED) {
        fprintf(stderr, "ERROR: Failed to mmap file!\n");
        close(vs->fd);
        exit(84);
    }
}

bool asm_fc(char *name)
{
    if (name[0] == '_')
        return true;
    if (strstr(name, "stdin") != NULL)
        return true;
    if (strstr(name, "stdout") != NULL)
        return true;
    if (strstr(name, "stderr") != NULL)
        return true;
    if (strstr(name, "GLIBC") != NULL)
        return true;
    return false;
}

void exec_re_loop(sd_t *sd, list_t *list)
{
    for (int j = 0; j < sd->symtab_size; j += sd->symtab_entry_size) {
        Elf64_Sym *sym = (Elf64_Sym *)&sd->symtab[j];
        char *name = sd->symstrtab + sym->st_name;
        bool from_compiled = sym->st_shndx != SHN_UNDEF;
        bool fc = ELF64_ST_TYPE(sym->st_info) == STT_FUNC;
        if (sym->st_size == 0 || !from_compiled || asm_fc(name) || !fc)
            continue;
        if (name[0] != '\0') {
            add_item(list, strdup(name), sym->st_value);
        }
    }
}

void exec_re(Elf64_Ehdr *ehdr, Elf64_Shdr *shdrs, vs_t *vs, list_t *list)
{
    for (int i = 0; i < ehdr->e_shnum; i++) {
        if (shdrs[i].sh_type == SHT_SYMTAB || shdrs[i].sh_type == SHT_DYNSYM) {
            char *symtab = vs->data + shdrs[i].sh_offset;
            int symtab_size = shdrs[i].sh_size;
            int symtab_entry_size = shdrs[i].sh_entsize;
            Elf64_Shdr *symstr_shdr = &shdrs[shdrs[i].sh_link];
            char *symstrtab = vs->data + symstr_shdr->sh_offset;
            sd_t *sym_data = malloc(sizeof(sd_t));
            sym_data->symtab = symtab;
            sym_data->symtab_size = symtab_size;
            sym_data->symtab_entry_size = symtab_entry_size;
            sym_data->symstrtab = symstrtab;
            exec_re_loop(sym_data, list);
        }
    }
}

list_t *get_items(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <elf-file>\n", argv[0]);
        exit(84);
    }
    vs_t *vs = malloc(sizeof(vs_t));
    list_t *list = init_list();
    manage_error(argc, argv, vs);
    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)vs->data;
    Elf64_Shdr *shdrs = (Elf64_Shdr *)(vs->data + ehdr->e_shoff);
    exec_re(ehdr, shdrs, vs, list);
    munmap(vs->data, vs->sb.st_size);
    close(vs->fd);
    return list;
}
