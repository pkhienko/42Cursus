NAME			=	Interface_\&_recap

SOURCES			=	source/main.cpp \
					source/AMateria.cpp \
					source/Ice.cpp \
					source/Cure.cpp \
					source/ICharacter.cpp \
					source/Character.cpp \
					source/IMateriaSource.cpp \
					source/MateriaSource.cpp

OBJECTS			= 	$(SOURCES:.cpp=.o)

C++				= 	c++ 

FLAGS			= 	-Wall -Werror -Wextra -pedantic -std=c++98 -g3

HEADER			=	-Iinclude

RM				= 	rm -f

all:			$(NAME)

$(NAME):		Makefile $(OBJECTS)
				@ echo "\033[1;33m---- Compiling Interface & recap ----"
				@ $(C++) $(HEADER) $(FLAGS) $(OBJECTS) -o $(NAME)
				@ echo "\033[32m     Interface & recap Compiled!"
				@ echo "\033[1;33m-------------------------------------"


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