#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat( const std::string name, const int grade ) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name + "_copy")
{ 
	*this = other;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {}

const std::string	&Bureaucrat::getName( void ) const { return (this->_name); }

int	Bureaucrat::getGrade( void ) const { return (this->_grade); }

void	Bureaucrat::increment( void )
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrement( void )
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is too High (must be >= 1)");
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is too Low (must be <= 150)");
}

std::ostream &operator<<( std::ostream &os, const Bureaucrat &other )
{
	return (os << GREEN << other.getName() << RESET ", bureaucrat grade " YELLOW << other.getGrade() << RESET);
}