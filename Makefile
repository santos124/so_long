NAME		=	so_long
NAME_B		=	so_long_b
HEADER		=	SRC/so_long.h
HEADER_B	=	SRC_B/so_long_bonus.h
LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIBMLXDIR	=	mlx
LIBMLX		=	$(LIBMLXDIR)/libmlx.a
CFLAGS		=	-Wall -Werror -Wextra
CC			=	clang
SRC			=	SRC/main.c SRC/moves.c SRC/errors.c SRC/read_map.c\
				SRC/free.c SRC/render.c
OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT) $(LIBMLX) $(HEADER) Makefile
			$(CC) $(CFLAGS)\
			-lmlx -framework OpenGL -framework Appkit\
			$(LIBFT) $(LIBMLX) $(OBJ) -o $(NAME)

$(LIBFT)	: Makefile $(LIBFTDIR)/libft.h $(LIBFTDIR)/Makefile $(LIBFTDIR)
			make -C $(LIBFTDIR)

$(LIBMLX)	: Makefile
			make -C $(LIBMLXDIR)

%.o			:	%.c Makefile $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

bonus		: clean_m
			make -f Makefile_b

clean		:
			rm -f $(OBJ)
			make -f Makefile_b clean
			make -C $(LIBFTDIR) clean
			make -C $(LIBMLXDIR) clean

clean_m		:
			rm -f $(OBJ) ./so_long

fclean		:	clean
			make -f Makefile_b fclean
			rm -f $(LIBMLX)
			rm -f $(LIBFT)
			rm -f $(NAME)

re			:	fclean all

.PHONY: all libft clean fclean re bonus