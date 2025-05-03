#include "PhoneBook.hpp"

std::string	ft_touppercase(std::string str)
{
	for (std::string::size_type i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int main( void )
{
	PhoneBook	phonebook;
	std::string	options;

	while (true)
	{
		std::cout << "\n|-------- Select your options --------|" << std::endl;
		std::cout << "| ADD : save a new contact            |" << std::endl;
		std::cout << "| SEARCH : display a specific contact |" << std::endl;
		std::cout << "| EXIT : exit the program             |" << std::endl;
		std::cout << "|-------------------------------------|\n" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, options);
		options = ft_touppercase(options);

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
