NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c push_moves.c push_smallsort.c push_largesort.c push_medieumsort.c push_mysort.c push_swap.c push_utils.c

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo PUSH_SWAP IS READY TO LAUNCH !!!
clean :
	@rm -rf $(OBJS)
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME) $(OBJS)
	@echo PUSH_SWAP RESET ...
re : fclean all