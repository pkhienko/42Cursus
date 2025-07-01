#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private :
		Brain	*_brain;
		
	public :
		Cat( void );
		Cat( const Cat &other );

		Cat	&operator=( const Cat &other );

		~Cat( void );

		void	getIdea( int n );
		void	makeSound( void ) const;
		void	setIdea( std::string idea, int n );
};

#endif
