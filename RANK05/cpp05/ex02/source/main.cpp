#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << MAGENTA << "========= Test AForm & Concrete Forms =========" << RESET << std::endl;

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 1: Invalid Bureaucrat Grades" << RESET << std::endl;
    try {
        Bureaucrat high("High", 0); // invalid: < 1
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }
    try {
        Bureaucrat low("Low", 200); // invalid: > 150
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 2: Execute before signing" << RESET << std::endl;
    try {
        Bureaucrat A("Boss", 1);
        PresidentialPardonForm B("Arthur Dent");
        std::cout << A << std::endl;
        std::cout << B << std::endl;

        // call through AForm::execute to trigger NotSigned
        try {
            B.execute(A);
        } catch (const AForm::NotSignedException &e) {
            std::cerr << YELLOW << "NotSigned caught: " << e.what() << RESET << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 3: Signing with too low grade (beSigned throws)" << RESET << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        RobotomyRequestForm robo("Bender");
        std::cout << intern << std::endl;
        std::cout << robo << std::endl;

        try {
            robo.beSigned(intern); // need 72 to sign; intern=150 -> fail
        } catch (const std::exception &e) {
            std::cerr << YELLOW << intern.getName()
                      << " cannot sign " << robo.getName() << ": "
                      << e.what() << RESET << std::endl;
        }
        std::cout << robo << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 4: Execute with insufficient executor grade" << RESET << std::endl;
    try {
        Bureaucrat signer("Signer", 50);   // can sign Shrubbery (needs 145) and Robotomy (needs 72)? -> 50 <= 72 OK
        Bureaucrat execMid("ExecMid", 50); // exec Robotomy needs 45 -> 50 too low
        RobotomyRequestForm robo("R2D2");

        std::cout << signer << std::endl;
        std::cout << execMid << std::endl;

        signer.signForm(robo); // should sign ok
        try {
            robo.execute(execMid); // should throw GradeTooLow
        } catch (const std::exception &e) {
            std::cerr << YELLOW << execMid.getName()
                      << " cannot execute " << robo.getName() << ": "
                      << e.what() << RESET << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 5: Happy path — sign & execute all forms" << RESET << std::endl;
    try {
        Bureaucrat top("Top", 1);
        Bureaucrat mid("Mid", 100);

        ShrubberyCreationForm shrub("home");        // sign 145 / exec 137
        RobotomyRequestForm   robo("Bender");       // sign 72 / exec 45
        PresidentialPardonForm pardon("Ford Prefect"); // sign 25 / exec 5

        std::cout << top << std::endl;
        std::cout << mid << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        // sign with appropriate grades
        mid.signForm(shrub);    // OK (100 <= 145)
        mid.signForm(robo);     // fail (100 > 72)
        top.signForm(robo);     // OK
        mid.signForm(pardon);   // fail (100 > 25)
        top.signForm(pardon);   // OK

        std::cout << shrub << std::endl;
        std::cout << robo << std::endl;
        std::cout << pardon << std::endl;

        // execute with appropriate grades
        mid.executeForm(shrub);   // OK (100 <= 137)
        mid.executeForm(robo);    // fail (100 > 45)
        top.executeForm(robo);    // OK (random success/fail message)
        top.executeForm(pardon);  // OK
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 6: Robotomy randomness (10 runs)" << RESET << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        RobotomyRequestForm robo("HAL-9000");
        boss.signForm(robo);
        for (int i = 0; i < 10; ++i) {
            boss.executeForm(robo);
        }
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 7: Shrubbery file creation" << RESET << std::endl;
    try {
        Bureaucrat worker("Worker", 100);
        ShrubberyCreationForm shrub("christmas_tree");
        worker.signForm(shrub);     // OK
        worker.executeForm(shrub);  // creates christmas_tree_shrubbery
        std::cout << GREEN << "(Check the file: christmas_tree_shrubbery)" << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    // ----------------------------------------------------
    std::cout << BLUE << "\nTest 8: Copy & Assignment of concrete forms" << RESET << std::endl;
    try {
        PresidentialPardonForm p1("Zaphod");
        PresidentialPardonForm p2 = p1; // copy-construct
        PresidentialPardonForm p3("Trillian");
        p3 = p1;                        // copy-assign

        std::cout << p1 << std::endl;
        std::cout << p2 << std::endl;
        std::cout << p3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n========= End of Tests =========" << RESET << std::endl;
    return 0;
}
