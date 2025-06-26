NAME            = philo

SRC_DIR		 	= src

SOURCES         = $(SRC_DIR)/main.c \
				  $(SRC_DIR)/init.c \
				  $(SRC_DIR)/time.c \
				  $(SRC_DIR)/utils.c \
				  $(SRC_DIR)/parsing.c \
				  $(SRC_DIR)/simulator.c \
				  $(SRC_DIR)/stop_thread.c \
				  $(SRC_DIR)/write_status.c \
				  $(SRC_DIR)/error_handle.c \
				  $(SRC_DIR)/thread_control.c

OBJ_DIR         = obj

OBJECTS         = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)/%.o)

CC              = cc

FLAGS           = -Wall -Werror -Wextra -pthread

HEADER			= -I include

RM              = rm -rf

MODE			= none

ifeq ($(MODE), DEBUG)
	FLAGS		+= -fsanitize=thread -g -D DEBUG_MODE=true 
endif

all:            $(NAME)

$(NAME):		$(OBJECTS)
				@echo "\033[1;33m---- Compiling Philosopher Mandatory ----"
				@$(CC) $(HEADER) $(FLAGS) $(OBJECTS) -o $(NAME)
				@echo "\033[32mPhilosopher Compiled! \033[37mᕦ\033[33m(\033[31m♥\033[33m ⩊ \033[31m♥\033[33m )\033[37mᕤ\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(HEADER) $(FLAGS) -c $< -o $@

clean:
				@echo "\033[1;33m--- Cleaning up object files ---"
				@$(RM) $(OBJ_DIR)
				@echo "\033[1;32m--- Object files removed! ---\033[0m"

fclean:         clean
				@echo "\033[1;33m--- Cleaning up all ---"
				@$(RM) $(NAME)
				@echo "\033[1;32m--- Executable removed! ---\033[0m"

re:             fclean all

.PHONY:         all clean fclean re
