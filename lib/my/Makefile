##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

SRC	=	my_towordtab.c			\
		my_getnbr.c			\
		my_putchar.c			\
		my_revstr.c			\
		my_strcat.c			\
		my_itoa.c			\
		my_strlen.c			\
		my_putstr.c			\
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/my.h
	mv libmy.a ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	clean all

%.o:	%.c
		@echo "$< => $@"
		@$(CC) $(CFLAGS) -c -o $@ $<
