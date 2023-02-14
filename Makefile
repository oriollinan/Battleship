##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile create binary for antman and giantman
##

all:
			make -C lib/
			make -C src/

clean:
			make clean -C lib/
			make clean -C src/

fclean:		clean
			make fclean -C lib/
			make fclean -C src/

re:			fclean all
