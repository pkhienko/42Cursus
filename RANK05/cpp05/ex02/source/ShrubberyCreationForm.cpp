#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", false, 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : AForm(other.getName() + "_copy", false, 145, 137), _target(other._target) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

std::string	ShrubberyCreationForm::getTarget( void ) const { return (this->_target); }

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	else if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	else
	{
		std::ofstream	outfile;

		outfile.open(this->getTarget().append("_shrubbery").c_str());
		if (!outfile.is_open())
			throw std::runtime_error("Could not open file");
		else
		{
			outfile <<
			"		  ⠀⠀⠀⠈" << std::endl <<
			"⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⡰⡇⠁" << std::endl <<
			"⠀⠀⠀⠀⠀⠀⠀⠀⠰⢾⠇⠨⡦⠀⠂" << std::endl <<
			"⠀⠀⠀⠀⠀⠀⡀⠀⢈⣹⠜⠻⢾⠃" << std::endl <<
			"⠀⠀⠀⠀⠀⠀⠁⢠⣿⡵⠾⣻⣶⠿⠦" << std::endl <<
			"⠀⠀⠀⠀⢀⠀⢀⣠⣮⣦⡶⠻⠛⢶⣄⡀⠁" << std::endl <<
			"⠀⠀⠀⠀⠀⠀⢀⣽⠏⠁⣠⣂⣦⣈⣝⣦⣄⠀⠈⠁" << std::endl <<
			"⠀⠀⠀⠀⠁⣠⣾⣵⣾⣾⠟⡙⠟⠿⣍⡉⠀⠀⠆" << std::endl <<
			"⠀⠰⠀⠀⠄⣠⣶⣾⣭⡶⠟⠻⣶⡰⣜⣳⣦⣄⠀⡀" << std::endl <<
			"⠀⠀⠀⢀⣠⣴⣿⣋⡴⣪⠎⣄⡙⠻⠿⣯⣉⠉" << std::endl <<
			"⠀⠂⠀⢀⣉⡭⢿⡛⣛⣵⠎⠀⠙⢾⣶⣦⣭⣷⣦⠐" << std::endl <<
			"⠀⠀⢈⣙⣿⡿⠿⠟⣋⢅⡄⡄⡐⣄⢤⣉⠷⢦⣄⣀⠠" << std::endl <<
			"⠐⠾⠿⢽⣷⡶⠶⡿⣓⣭⣾⣿⢷⣬⣓⢿⠿⠿⣯⣉⣁" << std::endl <<
			"⠀⠀⠀⠉⠉⠉⠛⠛⠉⢀⣿⢿⡀⠙⠋⠓⠿⠿⠏⠉⠉" << std::endl <<
			"⠀⠀⠀⠀⠀⠀⠠⠤⠶⠾⢿⡯⠷⠶⠤⠄" << std::endl;
			outfile.close();
		}
	}
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &other)
{
	return (os << GREEN "AForm:\t" RESET << other.getName() <<
			MAGENTA "\n\tTarget" BLUE " -> " YELLOW << other.getTarget() << RESET
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other.getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other.getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other.getExecuteGrade() << RESET);
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm *other)
{
	if (!other)
		return (os << "(Null ShrubberyCreationForm)");
	return (os << GREEN "AForm:\t" RESET << other->getName() <<
			MAGENTA "\n\tTarget" BLUE " -> " YELLOW << other->getTarget() << RESET
			MAGENTA "\n\tIs Signed" BLUE " -> " << (other->getIsSigned() == true ? GREEN "True" RESET : RED "False" RESET) <<
			MAGENTA "\n\tSign Grade" BLUE " -> " YELLOW << other->getSignGrade() << RESET <<
			MAGENTA "\n\tExecute Grade" BLUE " -> " YELLOW << other->getExecuteGrade() << RESET);
}
