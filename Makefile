CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra #-g -fsanitize=address -Wdeprecated-declarations

NAME	=	so_long 

SRC		=	src/ft_so_long.c \
			src/ft_collectexit.c \
			src/ft_errors.c \
			src/ft_errorsquare.c \
			src/ft_exitgame.c \
			src/ft_img_init.c \
			src/ft_movements.c \
			src/ft_paintfct.c \
			src/ft_updatemap.c \

OBJ 	=	$(SRC:.c=.o)

all: 		$(NAME)

$(NAME) : 	$(OBJ)
#			make -C mlx
			make -C ft_printf
			make -C libft
			$(CC) $(CFLAGS) $(SRC) ft_printf/libftprintf.a libft/libft.a mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o : %.c
# 			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
#			make clean -C mlx
			make clean -C ft_printf
			make clean -C libft
			rm -f $(OBJ)

fclean : 	clean
			make fclean -C ft_printf
			make fclean -C libft
			rm -f $(NAME)

re :		fclean all

.PHONY: 	all clean fclean re