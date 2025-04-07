NAME            = pipex

SOURCES         = src/pipex.c src/pipex_utils.c

SOURCES_BONUS   = src_bonus/pipex_bonus.c src_bonus/pipex_utils_bonus.c

OBJECTS         = $(SOURCES:.c=.o)

OBJECTS_BONUS   = $(SOURCES_BONUS:.c=.o)

CC              = cc

FLAGS           = -Wall -Werror -Wextra -fsanitize=address

AR              = ar -rsc

RM              = rm -f

all:            $(NAME)

$(NAME):		$(OBJECTS)
				@echo "\033[1;33m---- Compiling Libft ----"
				@make -C libft > /dev/null
				@echo "\033[32mLibft Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"
				@$(CC) $(FLAGS) $(OBJECTS) -Llibft -lft -o $(NAME)
				@echo "\033[33m---- Compiling Pipex Mandatory ----"
				@echo "\033[32mPipex Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"

bonus:			$(OBJECTS_BONUS)
				@echo "\033[1;33m---- Compiling Libft ----"
				@make -C libft > /dev/null
				@echo "\033[32mLibft Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"
				@$(CC) $(FLAGS) $(OBJECTS_BONUS) -Llibft -lft -o $(NAME)
				@echo "\033[33m---- Compiling Pipex Bonus ----"
				@echo "\033[32mPipex Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"

%.o: %.c
				@$(CC) $(FLAGS) -I src -I src_bonus -c $< -o $@

clean:
				@echo "\033[1;33m--- Cleaning up object files ---"
				@$(RM) $(OBJECTS) $(OBJECTS_BONUS)
				@echo "\033[32m--- Object files removed! ---"
				@make clean -C libft > /dev/null

fclean:         clean
				@echo "\033[1;33m--- Cleaning up all ---"
				@$(RM) $(NAME)
				@echo "\033[32m--- Executable removed! ---"
				@make fclean -C libft > /dev/null

re:             fclean all

.PHONY:         all clean fclean re
