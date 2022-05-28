NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_moves.c push_swap.c push_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
$(OBJS) :
	$(CC) $(CFLAGS) -c $(SRCS)
clean :
	rm -rf $(OBJS)
fclean :
	rm -rf $(NAME) $(OBJS)
re : fclean all