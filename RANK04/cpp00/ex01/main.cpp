#include "Contact.hpp"
#include "PhoneBook.hpp"

int main( void )
{
	PhoneBook	phonebook;
	std::string	options;

	while (true)
	{
		std::cout << "|-------- Select your options --------|" << std::endl;
		std::cout << "| ADD : save a new contact            |" << std::endl;
		std::cout << "| SEARCH : display a specific contact |" << std::endl;
		std::cout << "| EXIT                                |" << std::endl;
		std::cout << "|-------------------------------------|" << std::endl;;
		std::getline(std::cin, options);

		if (std::cin.eof())
			break ;
		else if (options.empty())
			std::cout << "No option selected." << std::endl;
		else if (options == "ADD")
			phonebook.addContact();
		else if (options == "SEARCH")
			phonebook.displayContact();
		else if (options == "EXIT")
			break ;
		else
			std::cout << "Invalid option: Please try again." << std::endl;
	}
	return (0);
}