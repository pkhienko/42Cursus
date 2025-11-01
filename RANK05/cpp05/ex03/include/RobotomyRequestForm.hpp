#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private :
		const std::string	_target;

	public :
		// Constructors
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &other );

		// Operator Overload
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &other );

		// Destructor
		~RobotomyRequestForm( void );

		// Getter
		std::string	getTarget( void ) const;

		// Methods
		void	execute( Bureaucrat const &executor ) const;
};

std::ostream &operator<<( std::ostream &os, const RobotomyRequestForm &other );
std::ostream &operator<<( std::ostream &os, const RobotomyRequestForm *other );

#endif