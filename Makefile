##
## EPITECH PROJECT, 2023
## B-PSU-400-LYN-4-1-ftrace-oscar.deschamps
## File description:
## Makefile
##

BIN       = ftrace
GXX       = gcc

SRC_D     = src/
OBJ_D     = obj/
DEP_D     = dep/
INC_D     = include/

SRC       = $(shell find $(SRC_D) -type f -name "*.c")
OBJ       = $(addprefix $(OBJ_D), $(notdir $(SRC:.c=.o)))
DEP       = $(addprefix $(DEP_D), $(notdir $(SRC:.c=.d)))

CFLAGS    = -Wall -I$(INC_D)

$(OBJ_D)%.o: $(SRC_D)%.c
	$(GXX) $(CFLAGS) -MMD -MP -MF \
		$(patsubst $(OBJ_D)%.o, $(DEP_D)%.d, $@) -c $< -o $@

all: $(BIN)

$(BIN): $(OBJ)
	$(GXX) $(OBJ) -o $(BIN)

-include $(DEP)

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(BIN)

re: fclean all
