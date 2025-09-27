#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private :
		const std::string	_target;

	public :
		// Constructors
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &other );

		// Operator Overload
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &other );

		// Destructor
		~ShrubberyCreationForm( void );

		// Getter
		std::string	&getTarget( void ) const;

		// Methods
		void	execute( Bureaucrat const &executor ) const;
};

std::ostream &operator<<( std::ostream &os, const ShrubberyCreationForm &other );

#endif