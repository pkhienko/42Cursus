#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << MAGENTA << std::endl << "========= Test Bureaucrat =========" << RESET << std::endl;

	std::cout << BLUE << std::endl << "Test 1: Construct with too LOW grade (151)"  << RESET << std::endl;
	try
	{
		Bureaucrat low("LowMan", 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << YELLOW << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << std::endl << "Test 2: Construct with too HIGH grade (0)"  << RESET << std::endl;
	try
	{
		Bureaucrat high("HighMan", 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << YELLOW << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}

	// -----------------------------------------------------------------------------------------------------

	std::cout << BLUE << std::endl << "Test 3: Increment boundary (start grade=1)"  << RESET << std::endl;
	Bureaucrat top("TopRank", 1);
	std::cout << top << std::endl;
	try
	{
		top.increment();
	}
	catch(const std::exception &e)
	{
		std::cerr << YELLOW << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << top << std::endl;

	std::cout << BLUE << std::endl << "Test 4: Decrement boundary (start grade=150)"  << RESET << std::endl;
	Bureaucrat bottom("BottomRank", 150);
	std::cout << bottom << std::endl;
	try
	{
		bottom.decrement();
	}
	catch(const std::exception &e)
	{
		std::cerr << YELLOW << "Exception caught: " << RED << e.what() << RESET << std::endl;
	}
	std::cout << bottom << std::endl;

	// -----------------------------------------------------------------------------------------------------

	std::cout << BLUE << std::endl << "Test 5: Normal inc/dec (start grade=100)"  << RESET << std::endl;
	Bureaucrat student("Student", 100);
	std::cout << student << std::endl;
	try
	{
		student.increment();
		std::cout << MAGENTA "After increment: "  << student << std::endl;
		student.decrement();
		std::cout << MAGENTA "After decrement: "  << student << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << "Unexpected exception: " << e.what() << RESET << std::endl;
	}

	// -----------------------------------------------------------------------------------------------------

	std::cout << BLUE << std::endl << "Test 6: Copy constructor & assignment"  << RESET << std::endl;
	Bureaucrat original("Original", 42);
	std::cout << MAGENTA "Original: " << original << std::endl;

	Bureaucrat copy(original);
	std::cout << MAGENTA "Copy constructed: " << copy << std::endl;

	Bureaucrat assigned("Dummy", 120);
	std::cout << MAGENTA "Before assign: " << assigned << std::endl;
	assigned = original;
	std::cout << MAGENTA "After assign: " << assigned << std::endl;

	return (0);
}
