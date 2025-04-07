NAME            = fractol

SOURCES         = $(wildcard src/*.c)

OBJECTS         = $(SOURCES:.c=.o)

CC              = cc

FLAGS           = -Wall -Werror -Wextra

HEADER			= -I include

AR				= ar -rcs

RM              = rm -f

all:            $(NAME)

$(NAME):		$(OBJECTS)
				@echo "\033[1;33m---- Compiling MinilibX ----"
				@make -sC minilibx-linux
				@echo "\033[1;32mMinilibX Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"
				@echo "\033[1;33m---- Compiling Libft ----"
				@make -sC libft
				@echo "\033[32mLibft Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ"
				@$(CC) $(HEADER) $(OBJECTS) -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm -Llibft -lft -o $(NAME)
				@echo "\033[33m---- Compiling Fract-ol Mandatory ----"
				@echo "\033[32mFract-ol Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ\033[0m"
%.o: %.c
				@$(CC) $(HEADER) -c $< -o $@

clean:
				@echo "\033[1;33m--- Cleaning up object files ---"
				@$(RM) $(OBJECTS)
				@make clean -sC libft
				@make clean -sC minilibx-linux
				@echo "\033[1;32m--- Object files removed! ---\033[0m"

fclean:         clean
				@echo "\033[1;33m--- Cleaning up all ---"
				@$(RM) $(NAME)
				@make fclean -sC libft
				@echo "\033[1;32m--- Executable removed! ---\033[0m"

re:             fclean all

.PHONY:         all clean fclean re
