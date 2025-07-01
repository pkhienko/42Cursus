#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <ctime>
# include <string>
# include <cstdlib>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

# define IDEAS 100

class Brain {
	private :
		std::string	_ideas[IDEAS];

	private :
		std::string	generateString( void );

	public :
		Brain( void );
		Brain( const Brain &other );

		Brain	&operator=( const Brain &other );

		~Brain( void );

		std::string	&getIdea( int n );
		void		setIdea( std::string idea, int n );
};

#endif
