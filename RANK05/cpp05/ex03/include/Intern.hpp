#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public :
		// Constructors
		Intern( void );
		Intern( const Intern &other );

		// Operator Overload
		Intern	&operator=( const Intern &other );

		// Destructor
		~Intern( void );

		// Methods
		AForm	*makeForm( const std::string &formName, const std::string &target ) const;

		// Exceptions
		class InvalidForm : public std::exception {
			public :
				virtual const char *what( void ) const throw();
		};
};

#endif
