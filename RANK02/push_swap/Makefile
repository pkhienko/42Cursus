NAME            = push_swap

NAME_BONUS		= checker

SOURCES         = $(wildcard src/*.c)

SOURCES_BONUS	= $(wildcard bonus/*.c)

OBJECTS         = $(SOURCES:.c=.o)

OBJECTS_BONUS	= $(SOURCES_BONUS:.c=.o)

CC              = cc

FLAGS           = -Wall -Werror -Wextra -fsanitize=address

HEADER			= -I include

AR				= ar -rcs

RM              = rm -f

all:            $(NAME)

$(NAME):		$(OBJECTS)
				@echo "\033[1;33m---- Compiling Libft ----"
				@make -sC libft
				@echo "\033[32mLibft Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"
				@$(CC) $(FLAGS) $(HEADER) $(OBJECTS) -Llibft -lft -o $(NAME)
				@echo "\033[33m---- Compiling Push_Swap Mandatory ----"
				@echo "\033[32mPush_Swap Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"

bonus:			$(OBJECTS) $(OBJECTS_BONUS)
				@echo "\033[1;33m---- Compiling Libft ----"
				@make -sC libft
				@echo "\033[32mLibft Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"
				@$(CC) $(FLAGS) $(HEADER) $(filter-out src/main.o, $(OBJECTS)) $(OBJECTS_BONUS) -Llibft -lft -o $(NAME_BONUS)
				@echo "\033[33m---- Compiling Checker Bonus ----"
				@echo "\033[32mChecker Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"


%.o: %.c
				@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean:
				@echo "\033[1;33m--- Cleaning up object files ---"
				@$(RM) $(OBJECTS) $(OBJECTS_BONUS)
				@echo "\033[32m--- Object files removed! ---"
				@make clean -sC libft

fclean:         clean
				@echo "\033[1;33m--- Cleaning up all ---"
				@$(RM) $(NAME) $(NAME_BONUS)
				@echo "\033[32m--- Executable removed! ---"
				@make fclean -sC libft

re:             fclean all

.PHONY:         all clean fclean re bonus
