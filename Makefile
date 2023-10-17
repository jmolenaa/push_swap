NAME = push_swap
CHECKER = checker
SRC_PUSH_SWAP = push_swap/main.c utils.c
SRC_QUICKSORT = algorithms/quicksort/quicksort.c algorithms/quicksort/quicksort_to_b.c algorithms/quicksort/quicksort_back.c algorithms/quicksort/quicksort_utils.c algorithms/quicksort/find_quickest.c algorithms/quicksort/find_quickest_a.c
SRC_ALGORITHM = algorithms/sort_three.c algorithms/small_lists.c algorithms/algorithm_utils.c algorithms/radix.c algorithms/pasjans.c algorithms/rotations.c
SRC_CHECKER = checker/main.c utils.c
SRC_CHECKER_OPERATIONS = checker/operations/swap.c checker/operations/push.c checker/operations/rotate.c checker/operations/reverse_rotate.c
SRC_PARSING = parsing/parsing.c parsing/list_functions_parsing.c parsing/parsing_utils.c
SRC_OPERATIONS = operations/swap.c operations/push.c operations/rotate.c operations/reverse_rotate.c
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:%.c=obj/%.o) $(SRC_OPERATIONS:%.c=obj/%.o) $(SRC_PARSING:%.c=obj/%.o) $(SRC_ALGORITHM:%.c=obj/%.o) $(SRC_QUICKSORT:%.c=obj/%.o)
OBJ_CHECKER = $(SRC_CHECKER:%.c=obj/%.o) $(SRC_CHECKER_OPERATIONS:%.c=obj/%.o) $(SRC_PARSING:%.c=obj/%.o)
OBJ_DIR = obj obj/parsing obj/operations obj/algorithms obj/algorithms/quicksort obj/checker obj/push_swap obj/checker/operations

# libft related variables
LIBFT = libft/libft.a
LIBFT_DIR = libft

# variables for compilation
CC = cc
INCLUDES = -I includes -I libft/includes
ifdef DEBUG
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
else
CFLAGS = -Wall -Werror -Wextra
endif

all: $(LIBFT_DIR) $(NAME)

$(NAME): $(OBJ_PUSH_SWAP) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(LIBFT_DIR):
	@git clone https://github.com/jmolenaa/Codam_libft $(LIBFT_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

obj/%.o: src/%.c |$(OBJ_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(LIBFT) $(NAME) $(CHECKER)
	@rm -rf $(LIBFT_DIR)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

debug: fclean
	$(MAKE) DEBUG=1 all

re: fclean all
