NAME = community_library

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

SRCS = main.c library.c display.c helper.c search.c
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -I$(LIBFT_DIR)

LIBFT = $(LIBFT_DIR)/libft.a

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created$(NC)"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "$(RED)✗ Objects removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(RED)✗ $(NAME) removed$(NC)"

re: fclean all

.PHONY: all clean fclean re