#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _idx_count(0) {}

PhoneBook::~PhoneBook( void ) {}

void	PhoneBook::addContact( void )
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
	int			idx;

	do {
		std::cout << "Enter your first name" << std::endl;
		std::getline(std::cin, first_name);
	} while (first_name.empty());
	do {
		std::cout << "Enter your last name" << std::endl;
		std::getline(std::cin, last_name);
	} while (last_name.empty());
	do {
		std::cout << "Enter your nickname" << std::endl;
		std::getline(std::cin, nick_name);
	} while (nick_name.empty());
	do {
		std::cout << "Enter your phone number" << std::endl;
		std::getline(std::cin, phone_number);
	} while (first_name.empty());
	do {
		std::cout << "Enter your darkest secret" << std::endl;
		std::getline(std::cin, darkest_secret);
	} while (first_name.empty());

	idx = _idx_count % MAX_CONTACT;
	contacts[idx] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret, idx);
	_idx_count++;
}

void	PhoneBook::displayContact( void ) 
{
	
}