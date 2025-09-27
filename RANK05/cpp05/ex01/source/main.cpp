#include "Form.hpp"

int main(void) {
	std::cout << MAGENTA << "========= Test Form =========" << RESET << std::endl;

	std::cout << BLUE << "\nTest 1: Invalid Form (sign=0, exec=10)" << RESET << std::endl;
	try {
		Form invalid("InvalidForm", false, 0, 10);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\nTest 2: Invalid Form (sign=200, exec=10)" << RESET << std::endl;
	try {
		Form invalid("InvalidForm", false, 200, 10);
	} catch (const std::exception &e) {
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\nTest 3: Valid Forms" << RESET << std::endl;
	Form nonSecret("nonSecretForm", false, 100, 80);
	Form secret("SecretForm", false, 40, 20);

	std::cout << nonSecret << std::endl;
	std::cout << secret << std::endl;

	std::cout << BLUE << "\nTest 4: Signing Forms" << RESET << std::endl;
	Bureaucrat A("A", 50);
	Bureaucrat B("B", 120);

	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << std::endl;

	A.signForm(nonSecret);		// A grade 50 <= 100, should sign
	B.signForm(nonSecret);		// B grade 120 > 100, fail
	A.signForm(secret);			// A grade 50 > 40, fail
	B.signForm(secret);			// B grade 120 > 40, fail

	std::cout << nonSecret << std::endl;
	std::cout << secret << std::endl;

	std::cout << BLUE << "\nTest 5: Copy & Assignment" << RESET << std::endl;
	Form fcopy = secret;
	std::cout << fcopy << std::endl;

	Form fassign("Dummy", false, 150, 150);
	fassign = nonSecret;
	std::cout << fassign << std::endl;

	return (0);
}
