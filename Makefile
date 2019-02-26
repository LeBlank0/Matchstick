##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	map_set.c		\
		matche.c		\
		map.c			\
		error.c			\
		player.c		\
		bot.c			\
		matchstick.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

LIBFLAGS	=	-L./lib -lmy

CFLAGS	=	-g -W -Wall -Wextra -Iinclude

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		make -C lib/my/ fclean
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(LIBFLAGS)

clean:
		rm -f $(OBJ)

fclean:		 clean
		rm -f lib/libmy.a
		rm -f $(NAME) $(OBJ)

re:		fclean all
