NAME			= libftprintf.a

SOURCES 		= ft_print_hex.c ft_print_ptr.c ft_print_unsigned.c ft_print_utility.c ft_printf.c

HEADERS 		= .

OBJECTS 		= $(SOURCES:.c=.o)


CC				= cc

FLAGS			= -Wall -Werror -Wextra

AR				= ar -rsc

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJECTS)
				$(AR) $(NAME) $(OBJECTS)

%.o:%.c
				$(CC) -I $(HEADERS) $< -o $@ -c $(FLAGS)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re