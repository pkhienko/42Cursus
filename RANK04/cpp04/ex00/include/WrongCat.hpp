#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		WrongCat( void );
		WrongCat( const WrongCat &other );

		WrongCat	&operator=( const WrongCat &other );

		~WrongCat( void );

		std::string	getType( void ) const;
		void		makeSound( void ) const;
};

#endif