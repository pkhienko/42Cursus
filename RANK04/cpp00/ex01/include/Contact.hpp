#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nick_name;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int			_index;

	public:
		Contact( void );
		~Contact( void );
		Contact( std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret, int idx );

		std::string	getFirst_name( void ) const;
		std::string	getLast_name( void ) const;
		std::string	getNick_name( void ) const;
		std::string	getPhone_number( void ) const;
		std::string	getDarkest_secret( void ) const;
		int			getIndex( void ) const;
};

#endif