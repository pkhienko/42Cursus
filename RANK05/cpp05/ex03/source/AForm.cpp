#include "AForm.hpp"

AForm::AForm( void ) : _name("AForm"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm( const std::string name, bool isSigned, const int signGrade, const int executeGrade ) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw AForm::GradeTooLowException();
	else if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm( const AForm &other ) : _name(other._name + "_copy"), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{ 
	*this = other;
}

AForm	&AForm::operator=( const AForm &other )
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm( void ) {}

const std::string	&AForm::getName( void ) const { return (this->_name); }

bool	AForm::getIsSigned( void ) const { return (this->_isSigned); }

int	AForm::getSignGrade( void ) const { return (this->_signGrade); }

int	AForm::getExecuteGrade( void ) const { return (this->_executeGrade); }

void	AForm::beSigned( Bureaucrat const &b )
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too High");
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too Low");
}

const char	*AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	return (os << GREEN "AForm:\t" RESET << other.getName() <<
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other.getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other.getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other.getExecuteGrade() << RESET);
}

std::ostream &operator<<(std::ostream &os, const AForm *other)
{
	if (!other)
		return (os << "(Null AForm)");
	return (os << GREEN "AForm:\t" RESET << other->getName() <<
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other->getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other->getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other->getExecuteGrade() << RESET);
}
