#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private :
		Brain	*_brain;

	public :
		Dog( void );
		Dog( const Dog &other );

		Dog	&operator=( const Dog &other );

		~Dog( void );

		void	getIdea( int n );
		void	makeSound( void ) const;
		void	setIdea( std::string idea, int n );
};

#endif