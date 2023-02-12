CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

LIBFT_DIR = libft/

SRC_DIR = src/

PS_OBJ_DIR = obj_ps/
CK_OBJ_DIR = obj_ck/

BONUS_DIR = checker_bonus/

INC_DIR = includes/

LIBFT = $(LIBFT_DIR)libft.a

SOURCES = arrays.c\
	exit.c\
	insert_back.c\
	insert_back_strat.c\
	main.c\
	minmax.c\
	ops_push.c\
	ops_reverse.c\
	ops_rotate.c\
	ops_swap.c\
	parsing.c\
	print.c\
	push_swap.c\
	quartile.c\
	run.c\
	run_little.c\
	simplify.c \
	stack.c\
	to_push.c

BONUS_SOURCES = check_bonus.c\
	checker_bonus.c\
	exit_bonus.c\
	ops_bonus.c\
	ops_push_bonus.c\
	ops_reverse_bonus.c\
	ops_rotate_bonus.c\
	ops_swap_bonus.c\
	parsing_bonus.c\
	run_bonus.c\
	stack_bonus.c\
	stdin_bonus.c

SHARED_SOURCES = stack.c\
	exit.c\
	print.c

BONUS_SRC_DIR = $(addprefix $(SRC_DIR), $(BONUS_DIR))

OBJ = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)
SHARED_OBJ = $(SHARED_SOURCES:.c=.o)

OBJS = $(addprefix $(PS_OBJ_DIR), $(OBJ))
BONUS_OBJS = $(addprefix $(CK_OBJ_DIR), $(BONUS_OBJ))
SHARED_OBJS = $(addprefix $(PS_OBJ_DIR), $(SHARED_OBJ))

all: $(NAME)
bonus: $(BONUS_NAME)

$(PS_OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_DIR)

$(CK_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_DIR)

$(NAME): $(PS_OBJ_DIR) $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -o  $@ $(OBJS) $(LIBFT)

$(BONUS_NAME): $(CK_OBJ_DIR) $(NAME) $(BONUS_OBJS)
	$(CC) $(FLAGS) -o $@  $(SHARED_OBJS) $(BONUS_OBJS) $(LIBFT)

$(PS_OBJ_DIR):
	mkdir  $(PS_OBJ_DIR)

$(CK_OBJ_DIR):
	mkdir $(CK_OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -fd $(PS_OBJ_DIR)
	rm -fd $(CK_OBJ_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus 
