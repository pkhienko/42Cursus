NAME			=	The_Job_Of_Your_Dreams

SOURCES			=	source/tests.cpp \
					source/Account.cpp

OBJECTS			=	$(SOURCES:.cpp=.o)

C++				=	c++ 

FLAGS			=	-Wall -Werror -Wextra -pedantic -std=c++98

HEADER			=	-Iinclude

RM				=	rm -f

all:			$(NAME)

$(NAME):		Makefile $(OBJECTS)
				@ echo "\033[1;33m---- Compiling The Job Of Your Dreams ----"
				@ $(C++) $(HEADER) $(FLAGS) $(OBJECTS) -o $(NAME)
				@ echo "\033[32m     The Job Of Your Dreams Compiled!"
				@ echo "\033[1;33m------------------------------------------"

%.o: %.cpp
				@ $(C++) $(HEADER) $(FLAGS) -c $< -o $@

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