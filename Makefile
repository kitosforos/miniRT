NAME = miniRT
LEAKS = -fsanitize=address -g3
LIBFT = libft/libft.a
SRCS = 
INC = -IUsers/${USER}/.brew/opt/readline/include -Iinc -Ilibft
LIB = -L/Users/${USER}/.brew/opt/readline/lib -lreadline
OBJS = $(patsubst src/%, obj/%, $(SRCS:.c=.o))
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
############################
$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS)  -g $^ -o $@ -Llibft -lft $(INC) $(LIB)

$(LIBFT):
		make bonus -C libft

all: $(NAME)

obj/%.o: src/%.c
		$(CC) $(CFLAGS) -c -g $< -o $@ $(INC)

clean:
		rm -f obj/*.o

fclean: clean
		rm -f $(NAME)
		make fclean -C libft

re: fclean $(NAME)
