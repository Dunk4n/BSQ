##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##


D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)bsq.c		\
		$(D_SRC)square.c	\
		$(D_SRC)display.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	bsq

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy

all	:	$(NAME)

libmy	:
		make -C $(D_LIB)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		$(MAKE) -C $(D_LIB) fclean
		rm -f $(NAME)
		rm -f *~

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	rm -f $(OBJ)

re	:
		$(MAKE) fclean
		$(MAKE) all

.PHONY	:	 all clean fclean re
