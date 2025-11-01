#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ) {}

Intern::Intern( const Intern &other )
{ 
	*this = other;
}

Intern	&Intern::operator=( const Intern &other )
{
	(void)other;
	return (*this);
}

Intern::~Intern( void ) {}

AForm	*Intern::makeForm( const std::string &formName, const std::string &target ) const
{
	std::string	forms[3] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			std::cout << MAGENTA "Intern" RESET " creates " YELLOW << forms[i] << RESET << std::endl;
			switch (i) {
				case 0: return (new ShrubberyCreationForm(target));
				case 1: return (new RobotomyRequestForm(target));
				case 2: return (new PresidentialPardonForm(target));
			};
		}
	}
	throw Intern::InvalidForm();
}

const char	*Intern::InvalidForm::what( void ) const throw()
{
	return (MAGENTA "Intern" RESET " could not find form named!");
}
