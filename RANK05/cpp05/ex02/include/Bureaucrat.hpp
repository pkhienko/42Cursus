#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <ctime>
# include <string>
# include <cstdlib>
# include <fstream>
# include <iostream>
# include <exception>
# include "AForm.hpp"

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class AForm;

class Bureaucrat {
	private :
		const std::string	_name;
		int					_grade;

	public :
		// Constructors
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat( const std::string name, const int grade );

		// Operator Overload
		Bureaucrat	&operator=( const Bureaucrat &other );

		// Destructor
		~Bureaucrat( void );

		// Getter
		const std::string	&getName( void ) const;
		int					getGrade( void ) const;

		// Methods
		void	increment( void );
		void	decrement( void );
		void	signForm( AForm &form );
		void	executeForm( AForm const &form ) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what( void ) const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what( void ) const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const Bureaucrat &other );

#endif
