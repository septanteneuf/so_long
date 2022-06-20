CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=address -Wdeprecated-declarations

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
			$(CC) $(CFLAGS) $(SRC) ft_printf/libftprintf.a libft/libft.a minilibx/libmlx.a -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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

# CC = gcc

# NAME = libft_so_long.a

# FLAGS = -Wall -Wextra -Werror

# MLX = -Lminilibx -lmlx -framework OpenGL -framework AppKit

# SRC = ft_so_long.c ft_img_init.c ft_paintfct.c ft_movements.c ft_errors.c \
# 	ft_exitgame.c ft_collectexit.c ft_updatemap.c ft_errorsquare.c

# LIBFT_PATH = ./libft

# MAKE = make

# all: $(NAME)

# $(NAME): *.c
# 	$(MAKE) -C ./libft
# 	cp ./libft/libft.a $(NAME)
# 	$(CC) $(FLAGS) -c $(SRC)
# 	ar rc $(NAME) *.o
# 	$(CC) $(FLAGS) -L. -lft_so_long ./minilibx/libmlx.a $(MLX) *.o -lz -o so_long

# clean:
# 	rm -f *.o
# 	rm -f *.out
# 	$(MAKE) clean -C $(LIBFT_PATH)

# fclean: clean
# 	rm -f $(NAME)
# 	rm -f so_long
# 	$(MAKE) fclean -C $(LIBFT_PATH)

# re: fclean all

# bonus:

