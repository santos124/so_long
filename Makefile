NAME			=	so_long
HEADER			=	SRC/so_long.h
LIBFTDIR		=	SRC_0/libft
LIBFT			=	$(LIBFTDIR)/libft.a
LIBMLXDIR		=	SRC_0/minilibx_opengl_20191021
LIBMLX			=	$(LIBMLXDIR)/libmlx.a
CFLAGS			=	-Wall -Werror -Wextra -g
CC				=	clang

SRC				=	SRC/main03.c

OBJ				=	$(SRC:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJ) $(LIBFT) $(LIBMLX) $(HEADER)
				$(CC) $(CFLAGS) -framework OpenGL -framework AppKit $(LIBFT) $(LIBMLX) $(OBJ) -o $(NAME)

$(LIBFT)		: Makefile $(LIBFTDIR)/libft.h $(LIBFTDIR)/Makefile $(LIBFTDIR)
				make -C $(LIBFTDIR)

$(LIBMLX)		: Makefile
				make -C $(LIBMLXDIR)

%.o				:	%.c Makefile $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@



clean			:
				rm -f $(OBJ)
				make -C $(LIBFTDIR) clean
				make -C $(LIBMLXDIR) clean

fclean			:	clean
				rm -f $(LIBMLX)
				rm -f $(LIBFT)
				rm -f $(NAME)

re				:	fclean all

.PHONY: all libft clean fclean re