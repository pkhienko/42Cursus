#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public :
		// Constructors
		Form( void );
		Form( const Form &other );
		Form( const std::string name, const bool isSigned, const int signGrade, const int executeGrade );

		// Operator Overload
		Form	&operator=( const Form &other );

		// Destructor
		~Form( void );

		// Getter
		const std::string	&getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecuteGrade( void ) const;

		// Methods
		void	beSigned( const Bureaucrat &b );

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

std::ostream &operator<<( std::ostream &os, const Form &other );
std::ostream &operator<<( std::ostream &os, const Form *other );

#endif
