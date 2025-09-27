#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", false, 145, 137), _target("Home") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : Form("ShrubberyCreationForm", false, 145, 137), _target(other._target + "_copy")
{ 
	*this = other;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	return (*this);
}

AForm::~AForm( void ) {}