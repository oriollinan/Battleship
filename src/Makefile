##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile create binary for antman
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-I./../include -g3

BACK =		../

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -L./../lib/ -lmy
			mv $(NAME) $(BACK)$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BACK)$(NAME)

re:			fclean all
