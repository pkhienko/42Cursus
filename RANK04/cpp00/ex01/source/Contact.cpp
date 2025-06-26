#include "Contact.hpp"

Contact::Contact( void ) {}

Contact::~Contact( void ) {}

Contact::Contact( std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret, int index )
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nick_name = nick_name;
	this->_phone_number = phone_number;
	this->_darkest_secret = darkest_secret;
	this->_index = index;
}

std::string	Contact::getFirst_name( void ) const { return (_first_name); }

std::string	Contact::getLast_name( void ) const { return (_last_name); }

std::string	Contact::getNick_name( void ) const { return (_nick_name); }

std::string	Contact::getPhone_number( void ) const { return (_phone_number); }

std::string	Contact::getDarkest_secret( void ) const { return (_darkest_secret); }

int	Contact::getIndex( void ) const { return (_index); }