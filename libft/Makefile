CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

NAME		=	libft.a

SRC			=	ft_strdup.c ft_strjoin.c ft_strlen.c \
				ft_substr.c gnl.c gnl_utils.c \

all:			$(NAME)

$(NAME):
				$(CC) $(FLAGS) -c $(SRC)
				ar rc $(NAME) *.o

clean:
				rm -f *.o *.out

fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY: 		all clean fclean re