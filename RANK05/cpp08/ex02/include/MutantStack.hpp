#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <list>
# include <stack>
# include <deque>
# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		// Constructors
		MutantStack( void );
		MutantStack( const MutantStack &other );

		// Operators Overload
		MutantStack	&operator=( const MutantStack &other );

		// Destructor
		~MutantStack( void );

		// Typedef Iterators
		typedef	typename Container::iterator iterator;
		typedef	typename Container::const_iterator const_iterator;
		typedef	typename Container::reverse_iterator reverse_iterator;
		typedef	typename Container::const_reverse_iterator const_reverse_iterator;

		 // Normal Iterators
		iterator	begin( void );
		iterator	end( void );

		// Const Iterators
		const_iterator	begin( void ) const;
		const_iterator	end( void ) const;

		// Reverse Iterators
		reverse_iterator	rbegin( void );
		reverse_iterator	rend( void );

		// Const Reverse Iterators
		const_reverse_iterator	rbegin( void ) const;
		const_reverse_iterator	rend( void ) const;
};

# include "../source/MutantStack.tpp"

#endif
