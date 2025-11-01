#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", false, 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm(other.getName() + "_copy", false, 72, 45), _target(other._target)
{ 
	*this = other;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

std::string	RobotomyRequestForm::getTarget( void ) const { return (this->_target); }

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	static int	counter = 0;

	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::srand(std::time(NULL) + ++counter);
		std::cout << BLUE "BrrRrrrrrrrRRrrRRRrRR..."  RESET << std::endl;
		if (std::rand() % 2)
			std::cout << YELLOW "\t" << this->getTarget() << RESET " has been robotomized " GREEN "successfully!" RESET << std::endl;
		else
			std::cout << "\tRobotomy " RED "failed." RESET << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &other)
{
	return (os << GREEN "AForm:\t" RESET << other.getName() <<
			MAGENTA "\n\tTarget" BLUE " -> " YELLOW << other.getTarget() << RESET
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other.getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other.getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other.getExecuteGrade() << RESET);
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm *other)
{
	if (!other)
		return (os << "(Null RobotomyRequestForm)");
	return (os << GREEN "AForm:\t" RESET << other->getName() <<
			MAGENTA "\n\tTarget" BLUE " -> " YELLOW << other->getTarget() << RESET
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other->getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other->getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other->getExecuteGrade() << RESET);
}

