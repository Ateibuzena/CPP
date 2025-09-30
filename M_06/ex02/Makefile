NAME = Identify

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g

SRC_DIR = src
OBJ_DIR = obj

SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# 🎨 Colors
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
MAGENTA  = \033[0;35m
PINK = \033[38;2;255;105;180m
CYAN     = \033[0;36m
WHITE    = \033[0;37m
RESET    = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(YELLOW)✅ Build complete: $(NAME)$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)✅ Object directories created.$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(CYAN)🔹 Compiling$(MAGENTA) $<$(CYAN) ->$(PINK) $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(GREEN)🗑️  Deleting object files...$(RESET)"
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(YELLOW)✅ Object cleanup complete.$(RESET)"

fclean: clean
	@echo "$(GREEN)🚮 Deleting file $(NAME)...$(RESET)"
	@$(RM) -f $(NAME)
	@echo "$(YELLOW)✅ Full cleanup complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
