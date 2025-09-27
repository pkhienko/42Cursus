#include "Form.hpp"

Form::Form( void ) : _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form( const std::string name, bool isSigned, const int signGrade, const int executeGrade ) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (this->_signGrade > 150 || this->_executeGrade > 150)
		throw Form::GradeTooLowException();
	else if (this->_signGrade < 1 || this->_executeGrade < 1)
		throw Form::GradeTooHighException();
}

Form::Form( const Form &other ) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{ 
	*this = other;
}

Form	&Form::operator=( const Form &other )
{
	if (this == &other)
		return (*this);
	this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form( void ) {}

const std::string	&Form::getName( void ) const { return (this->_name); }

bool	Form::getIsSigned( void ) const { return (this->_isSigned); }

int	Form::getSignGrade( void ) const { return (this->_signGrade); }

int	Form::getExecuteGrade( void ) const { return (this->_executeGrade); }

void	Form::beSigned( Bureaucrat &b ) {
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too High (must be >= 1)");
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too Low (must be <= 150)");
}

std::ostream &operator<<(std::ostream &os, const Form &other) {
	return (os << GREEN "Form: " <<  other.getName() << RESET
			MAGENTA "\n\tIs Signed" RED " -> " << (other.getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" RED " -> " YELLOW << other.getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" RED " -> " YELLOW << other.getExecuteGrade() << RESET);
}
