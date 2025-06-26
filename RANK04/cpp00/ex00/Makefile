NAME			=	megaphone

SOURCES			=	source/megaphone.cpp

OBJECTS			=	$(SOURCES:.cpp=.o)

C++				=	c++ 

FLAGS			=	-Wall -Werror -Wextra -pedantic -std=c++98

RM				=	rm -f

all:			$(NAME)

$(NAME):		Makefile $(OBJECTS)
				@ echo "\033[1;33m---- Compiling Megaphone ----"
				@ $(C++) $(FLAGS) $(OBJECTS) -o $(NAME)
				@ echo "\033[32m     Megaphone Compiled!"
				@ echo "\033[1;33m-----------------------------"


%.o: %.cpp
				@ $(C++) $(FLAGS) -c $< -o $@

clean:
				@ echo "\033[1;33m--- Cleaning up object files ---"
				@ $(RM) $(OBJECTS)
				@ echo "\033[32m--- Object files removed! ---"

fclean:			clean
				@ echo "\033[1;33m--- Cleaning up all ---"
				@ $(RM) $(NAME)
				@ echo "\033[32m--- Executable removed! ---"

re:				fclean all

.PHONY:			all clean fclean re