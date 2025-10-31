#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private :
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public :
		// Constructors
		AForm( void );
		AForm( const AForm &other );
		AForm( const std::string name, const bool isSigned, const int signGrade, const int executeGrade );

		// Operator Overload
		AForm	&operator=( const AForm &other );

		// Destructor
		virtual	~AForm( void );

		// Getter
		const std::string	&getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getSignGrade( void ) const;
		int					getExecuteGrade( void ) const;

		// Methods
		void			beSigned( Bureaucrat const &signer );
		virtual void	execute( Bureaucrat const &executor ) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what( void ) const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what( void ) const throw();
		};
		class FormNotSignedException : public std::exception {
			public :
				virtual const char *what( void ) const throw();
		};
};

std::ostream &operator<<( std::ostream &os, const AForm &other );

#endif
