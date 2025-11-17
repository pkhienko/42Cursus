NAME			=	RPN

SOURCES			=	source/main.cpp \
					source/RPN.cpp

OBJECTS			= 	$(SOURCES:.cpp=.o)

C++				= 	c++ 

FLAGS			= 	-Wall -Werror -Wextra -pedantic -std=c++98

HEADER			=	-Iinclude

RM				= 	rm -f

all:			$(NAME)

$(NAME):		Makefile $(OBJECTS)
				@ echo "\033[1;33m---- Compiling Reverse Polish Notation ----"
				@ $(C++) $(HEADER) $(FLAGS) $(OBJECTS) -o $(NAME)
				@ echo "\033[32m     Reverse Polish Notation Compiled!"
				@ echo "\033[1;33m-------------------------------------------\033[0m"

%.o: %.cpp
				@ $(C++) $(HEADER) $(FLAGS) -c $< -o $@

clean:
				@ echo "\033[1;33m--- Cleaning up object files ---"
				@ $(RM) $(OBJECTS)
				@ echo "\033[32m--- Object files removed! ---\033[0m"

fclean:			clean
				@ echo "\033[1;33m--- Cleaning up all ---"
				@ $(RM) $(NAME)
				@ echo "\033[32m--- Executable removed! ---\033[0m"

re:				fclean all

.PHONY:			all clean fclean re