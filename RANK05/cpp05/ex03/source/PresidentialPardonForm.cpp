#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", false, 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", false, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : AForm(other.getName() + "_copy", false, 25, 5), _target(other._target)
{ 
	*this = other;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( const PresidentialPardonForm &other )
{
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

std::string	PresidentialPardonForm::getTarget( void ) const { return (this->_target); }

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
		std::cout << YELLOW << this->getTarget() << RESET " has been " GREEN "pardoned" RESET " by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &other)
{
	return (os << GREEN "AForm:\t" RESET << other.getName() <<
			MAGENTA "\n\tTarget" BLUE " -> " YELLOW << other.getTarget() << RESET
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other.getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other.getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other.getExecuteGrade() << RESET);
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm *other)
{
	if (!other)
		return (os << "(Null PresidentialPardonForm)");
	return (os << GREEN "AForm:\t" RESET << other->getName() <<
			MAGENTA "\n\tTarget" BLUE " -> " YELLOW << other->getTarget() << RESET
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other->getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other->getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other->getExecuteGrade() << RESET);
}

