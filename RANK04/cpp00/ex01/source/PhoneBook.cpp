#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _idx_count(0) {}

PhoneBook::~PhoneBook( void ) {}

std::string	limit_str(std::string str);

void	PhoneBook::addContact( void )
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
	int			idx;

	do {
		std::cout << "Enter your first name\n> ";
		std::getline(std::cin, first_name);
	} while (first_name.empty());
	do {
		std::cout << "Enter your last name\n> ";
		std::getline(std::cin, last_name);
	} while (last_name.empty());
	do {
		std::cout << "Enter your nickname\n> ";
		std::getline(std::cin, nick_name);
	} while (nick_name.empty());
	do {
		std::cout << "Enter your phone number\n> ";
		std::getline(std::cin, phone_number);
	} while (first_name.empty());
	do {
		std::cout << "Enter your darkest secret\n> ";
		std::getline(std::cin, darkest_secret);
	} while (first_name.empty());

	idx = _idx_count % MAX_CONTACT;
	contacts[idx] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret, idx);
	_idx_count++;
}

void	print_str( std::string str, bool newline, bool first )
{
	if (first)
		std::cout << "|" << std::setw(10) << str << "|";
	else if (newline)
		std::cout << std::setw(10) << str << "|"  << std::endl ;
	else
		std::cout<< std::setw(10) << str << "|";
}

std::string	limit_str(std::string str)
{
	char					new_str[11];
	std::string::size_type	i;

	i = 0;
	for (; i < str.length(); i++)
	{
		if (i == 9)
		{
			new_str[i++] = '.';
			break ;
		}
		new_str[i] = str[i];
	}
	new_str[i] = '\0';
	return (std::string(new_str));
}

void	displayIdxContact( Contact contacts[], int i )
{
	std::string	idx;

	std::cout << "\nEnter index of contacts to show [0 - 7]\n> ";
	std::getline(std::cin, idx);
	if (idx.length() == 1 && (idx[0] >= '0' && idx[0] <= '7'))
	{
		i = idx[0] - '0';
		if (!contacts[i].getFirst_name()[0])
		{
			std::cout << "Error: No information" << std::endl;
			return ;
		}
		std::cout << "Index: " << contacts[i].getIndex() << std::endl;
		std::cout << "First Name: " << contacts[i].getFirst_name() << std::endl;
		std::cout << "Last Name: " << contacts[i].getLast_name() << std::endl;
		std::cout << "Nick Name: " << contacts[i].getNick_name() << std::endl;
		std::cout << "Phone Number: " << contacts[i].getPhone_number() << std::endl;
		std::cout << "Darkest secret: " << contacts[i].getDarkest_secret() << std::endl;
	}
	else
		std::cout << "Error: Index is out of range or wrong input" << std::endl;
}

void	PhoneBook::displayContact( void )
{
	int			i;

	i = 0;
	if (!contacts[0].getFirst_name()[0])
	{
		std::cout << "Error: Phonebook is empty!" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "|" << std::string(43, '-') << "|" << std::endl;
	print_str("Index", false, true);
	print_str("First Name", false, false);
	print_str("Last Name", false, false);
	print_str("Nickname", true, false);
	std::cout << "|" << std::string(43, '-') << "|" << std::endl;
	for (int i = 0; i < MAX_CONTACT; i++)
	{
		if (contacts[i].getFirst_name()[0])
		{
			std::cout << "|" << std::setw(10) << contacts[i].getIndex() << "|";
			print_str(limit_str(contacts[i].getFirst_name()), false, false);
			print_str(limit_str(contacts[i].getLast_name()), false, false);
			print_str(limit_str(contacts[i].getNick_name()), true, false);
		}
	}
	std::cout << "|" << std::string(43, '-') << "|" << std::endl;
	displayIdxContact(contacts, i);
}