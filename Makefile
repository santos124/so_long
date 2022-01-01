NAME		=	so_long
NAME_B		=	so_long_b
HEADER		=	SRC/so_long.h
HEADER_B	=	SRC_B/so_long_bonus.h
LIBFTDIR	=	SRC_0/libft
LIBFT		=	$(LIBFTDIR)/libft.a
LIBMLXDIR	=	SRC_0/mlx
LIBMLX		=	$(LIBMLXDIR)/libmlx.a
CFLAGS		=	-Wall -Werror -Wextra -g
# -fsanitize=address
CC			=	clang
SRC			=	SRC/main.c SRC/moves.c SRC/errors.c SRC/read_map.c\
				SRC/free.c SRC/render.c
SRC_B		=	SRC_B/main_bonus.c SRC_B/moves_bonus.c SRC_B/errors_bonus.c\
				SRC_B/read_map_bonus.c SRC_B/free_bonus.c SRC_B/render_bonus.c
OBJ			=	$(SRC:.c=.o)
OBJ_B		=	$(SRC_B:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT) $(LIBMLX) $(HEADER)
			$(CC) $(CFLAGS) -framework OpenGL -framework AppKit  $(LIBFT) $(LIBMLX) $(OBJ) -o $(NAME)

$(LIBFT)	: Makefile $(LIBFTDIR)/libft.h $(LIBFTDIR)/Makefile $(LIBFTDIR)
			make -C $(LIBFTDIR)

$(LIBMLX)	: Makefile
			make -C $(LIBMLXDIR)

%.o			:	%.c Makefile $(HEADER) $(HEADER_B)
			$(CC) $(CFLAGS) -c $< -o $@

bonus		:	$(NAME_B)

$(NAME_B)	:	$(OBJ_B) $(LIBFT) $(LIBMLX) $(HEADER_B)
			$(CC) $(CFLAGS) -framework OpenGL -framework AppKit  $(LIBFT) $(LIBMLX) $(OBJ_B) -o $(NAME_B)

clean		:
			@rm -f $(OBJ) $(OBJ_B)
			@make -C $(LIBFTDIR) clean
			@make -C $(LIBMLXDIR) clean

fclean		:	clean
			@rm -f $(LIBMLX)
			@rm -f $(LIBFT)
			@rm -f $(NAME) $(NAME_B)

re			:	fclean all

.PHONY: all libft clean fclean re bonus