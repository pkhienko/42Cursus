#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <ctime>
# include <vector>
# include <string>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <utility>
# include <sstream>
# include <iostream>
# include <exception>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

class PmergeMe
{
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
		double				_dequeTime;
		double				_vectorTime;

		// Private Methods
		// Deque
		std::deque< std::pair<int, int> >	makePairDeque( const std::deque<int> &deq );
		std::deque<int>						createPendDeque( std::deque< std::pair<int, int> > &pairs, const std::deque<int> &sortedMain );
		void                                binarySearchInsertDeque( std::deque<int> &deq, int val );
		void								insertPendDeque( std::deque<int> &mainChain, const std::deque<int> &pendChain );
	    void   								sortDeque( std::deque<int> &deq );
		
		// Vector
		std::vector< std::pair<int, int> >	makePairVector( const std::vector<int> &vec );
		std::vector<int>					createPendVector( std::vector< std::pair<int, int> > &pairs, const std::vector<int> &sortedMain );
		void                                binarySearchInsertVector( std::vector<int> &vec, int val );
		void								insertPendVector( std::vector<int> &mainChain, const std::vector<int> &pendChain );
	    void   								sortVector( std::vector<int> &vec );

		// Utils
		size_t		getJacobsthal( size_t n );
		void		parseArg( int ac, char **av );

		// Helper
		template <typename Container>
		void	printContainer( const Container &container );

		// Exception
		class ErrorException : public std::exception {
			protected :
				std::string	_msg;

			public :
				ErrorException( const std::string &msg );

				virtual ~ErrorException( void ) throw();

				virtual const char	*what( void ) const throw();
		};

	public:
		// Constructors
		PmergeMe( void );
		PmergeMe( const PmergeMe &other );

		// Operators Overload
		PmergeMe	&operator=( const PmergeMe &other );

		// Destructor
		~PmergeMe( void );

		// Getter
		double	getDequeTime( void ) const;
		double	getVectorTime( void ) const;

		// Public Methods
		void	execute( int ac, char **av );
};

#endif
