#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

static void test_1( void )
{ 
    std::cout << BLUE "\nTest 1: Invalid Bureaucrat Grades" RESET << std::endl;

    try {
        Bureaucrat high("High", 0); // Invalid: < 1
    } catch (const std::exception &e) {
        std::cerr << RED "Exception caught: " RESET << e.what() << std::endl;
    }
    try {
        Bureaucrat low("Low", 200); // Invalid: > 150
    } catch (const std::exception &e) {
        std::cerr << RED "Exception caught: " RESET << e.what() << std::endl;
    }
}

static void test_2( void )
{
    std::cout << BLUE "\nTest 2: Execute before signing" RESET << std::endl;

    Bureaucrat a("A", 1);
    AForm *b = new PresidentialPardonForm("B");

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a.executeForm(*b);   

    delete b;
}

static void test_3( void )
{
    std::cout << BLUE << "\nTest 3: Signing with too low grade" << RESET << std::endl;

    Bureaucrat a("A", 150);
    AForm *b = new RobotomyRequestForm("B");
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    a.signForm(*b);
    std::cout << b << std::endl;
    
    delete b;
}

static void test_4( void )
{
    std::cout << BLUE << "\nTest 4: Execute with insufficient executor grade" << RESET << std::endl;

    Bureaucrat a("A", 140);
    AForm *b = new ShrubberyCreationForm("B");

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    a.signForm(*b); // should sign ok
    a.executeForm(*b); // should throw GradeTooLow
    std::cout << b << std::endl;

    delete b;
}

static void test_5( void )
{
    std::cout << BLUE << "\nTest 5: Sign & Execute all forms" << RESET << std::endl;

    Bureaucrat top("Top", 1);
    Bureaucrat mid("Mid", 100);

    ShrubberyCreationForm *shrub = new ShrubberyCreationForm("Home");                   // sign 145 / exec 137
    RobotomyRequestForm   *robot = new RobotomyRequestForm("Bumblebee");                // sign 72 / exec 45
    PresidentialPardonForm *pres = new PresidentialPardonForm("Prayut Chan-O-Cha");     // sign 25 / exec 5

    std::cout << top << std::endl;
    std::cout << mid << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pres << std::endl;

    // sign with appropriate grades
    mid.signForm(*shrub);      // OK (100 <= 145)
    mid.signForm(*robot);      // fail (100 > 72)
    top.signForm(*robot);      // OK
    mid.signForm(*pres);       // fail (100 > 25)
    top.signForm(*pres);       // OK

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pres << std::endl;

    // execute with appropriate grades
    mid.executeForm(*shrub);   // OK (100 <= 137)
    mid.executeForm(*robot);    // fail (100 > 45)
    top.executeForm(*robot);    // OK (random success/fail message)
    top.executeForm(*pres);  // OK

    delete shrub;
    delete robot;
    delete pres;
}

static void test_6( void )
{
    std::cout << BLUE << "\nTest 6: Shrubbery file creation" << RESET << std::endl;

    Bureaucrat worker("Worker", 100);
    ShrubberyCreationForm shrub("Christmas_Tree");
    worker.signForm(shrub);     // OK
    worker.executeForm(shrub);  // creates christmas_tree_shrubbery
}

static void test_7( void )
{
    std::cout << BLUE << "\nTest 7: Robotomy randomness (10 runs)" << RESET << std::endl;

    Bureaucrat boss("Boss", 1);
    RobotomyRequestForm robo("Terminator-1000");

    boss.signForm(robo);
    for (int i = 0; i < 10; ++i)
        boss.executeForm(robo);
}

static void test_8( void )
{
    std::cout << BLUE << "\nTest 8: Presidential Pardon " << RESET << std::endl;

    Bureaucrat boss("Boss", 1);
    PresidentialPardonForm pres("Prayut Chan-O-Cha");

    std::cout << boss << std::endl;
    std::cout << pres << std::endl;

    boss.signForm(pres);
    boss.executeForm(pres);
}

int main ( void )
{
    std::cout << MAGENTA "\n========= Test AForm & Concrete Forms =========\n" RESET << std::endl;
    try {
        while (true) {
            char choice = 0;
            std::cin >> choice;
            
            switch (choice) {
                case 'a': test_1(); test_2(); test_3(); test_4(); test_5(); test_6(); test_7(); test_8(); break ;
                case '1': test_1(); break ;
                case '2': test_2(); break ;
                case '3': test_3(); break ;
                case '4': test_4(); break ;
                case '5': test_5(); break ;
                case '6': test_6(); break ;
                case '7': test_7(); break ;
                case '8': test_8(); break ;
                case 'x': std::cout << MAGENTA << "\n========= End of Tests =========" << RESET << std::endl; return (0);
                default: break ;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }
    std::cout << MAGENTA << "\n========= End of Tests =========" << RESET << std::endl;
    return (0);
}
