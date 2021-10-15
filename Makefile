NAME			=	so_long
HEADER			=	SRC/so_long.h
LIBFTDIR		=	SRC_0/libft
LIBFT			=	$(LIBFTDIR)/libft.a
CFLAGS			=	-Wall -Werror -Wextra
CC				=	clang
SRC				=	SRC/main.c

OBJ				=	$(SRC:.c=.o)


all				:	$(NAME)

$(NAME)			:	$(OBJ) $(LIBFT)
				$(CC) -o $@ $(OBJ) $(LIBFT)

%.o				:	%.c Makefile $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)		: Makefile
				make -C $(LIBFTDIR)

clean			:
				rm -f $(OBJ)
				make -C $(LIBFTDIR) clean

fclean			:	clean
				rm -f $(NAME)

re				:	fclean all

.PHONY: all libft clean fclean re