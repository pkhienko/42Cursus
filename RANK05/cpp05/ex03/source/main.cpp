#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ( void )
{
    std::cout << MAGENTA "\n========= Test Intern =========\n" RESET << std::endl;
    
    Intern      intern;
    AForm       *form;
    Bureaucrat  *bob = new Bureaucrat("Bob", 3);

    try {
        form = intern.makeForm("shrubbery creation", "42");
        delete form;
        form = intern.makeForm("robotomy request", "GPT");
        delete form;
        form = intern.makeForm("presidential pardon", "Ing");
        delete form;
        form = intern.makeForm("random form", "CEO");
        delete form;
    } catch (const std::exception &e) {
        std::cerr << RED "Exception caught: " RESET << e.what() << std::endl;
    }

    form = intern.makeForm("shrubbery creation", "KMITL");
    bob->signForm(*form);
    bob->executeForm(*form);
    delete form;
    delete bob;

    std::cout << MAGENTA << std::endl << "========= End of Tests =========" << RESET << std::endl;
    return (0);
}
