#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# ifndef MAX_CONTACT
#  define MAX_CONTACT 8
# endif

class PhoneBook {
	private:
		Contact	contacts[MAX_CONTACT];
		int		_idx_count;
	
	public:
		PhoneBook( void );
		~PhoneBook( void );
		
		void	addContact( void );
		void	displayContact( void );
};

#endif