NAME			=	At_least_this_beats_coffee-making

SOURCES			=	source/main.cpp \
					source/AForm.cpp \
					source/Intern.cpp \
					source/Bureaucrat.cpp \
					source/RobotomyRequestForm.cpp \
					source/ShrubberyCreationForm.cpp \
					source/PresidentialPardonForm.cpp

OBJECTS			= 	$(SOURCES:.cpp=.o)

C++				= 	c++ 

FLAGS			= 	-Wall -Werror -Wextra -pedantic -std=c++98

HEADER			=	-Iinclude

RM				= 	rm -f

all:			$(NAME)

$(NAME):		Makefile $(OBJECTS)
				@ echo "\033[1;33m---- Compiling At least this beats coffee-making ----"
				@ $(C++) $(HEADER) $(FLAGS) $(OBJECTS) -o $(NAME)
				@ echo "\033[32m     At least this beats coffee-making Compiled!"
				@ echo "\033[1;33m-----------------------------------------------------"


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