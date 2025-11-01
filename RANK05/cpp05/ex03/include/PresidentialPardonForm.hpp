#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private :
		const std::string	_target;

	public :
		// Constructors
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &other );

		// Operator Overload
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &other );

		// Destructor
		~PresidentialPardonForm( void );

		// Getter
		std::string	getTarget( void ) const;

		// Methods
		void	execute( Bureaucrat const &executor ) const;
};

std::ostream &operator<<( std::ostream &os, const PresidentialPardonForm &other );
std::ostream &operator<<( std::ostream &os, const PresidentialPardonForm *other );

#endif