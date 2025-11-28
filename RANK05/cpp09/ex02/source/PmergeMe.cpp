#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) : _deque(std::deque<int>()), _vector(std::vector<int>()), _dequeTime(0.0), _vectorTime(0.0) {}

PmergeMe::PmergeMe( const PmergeMe &other ) { *this = other; }

PmergeMe	&PmergeMe::operator=( const PmergeMe &other )
{
	if (this != &other)
	{
		this->_deque = other._deque;
		this->_vector = other._vector;
		this->_dequeTime = other._dequeTime;
		this->_vectorTime = other._vectorTime;
	}
	return (*this);
}

PmergeMe::~PmergeMe( void ) {}

double	PmergeMe::getDequeTime( void ) const { return (this->_dequeTime); }

double	PmergeMe::getVectorTime( void ) const { return (this->_vectorTime); }

size_t	PmergeMe::getJacobsthal( size_t n )
{
	static std::vector<size_t>	jacobCache;
	size_t						size;

	if (jacobCache.empty())
	{
		jacobCache.reserve(32);
		jacobCache.push_back(0);
		jacobCache.push_back(1);
	}
	size = jacobCache.size() - 1;
	while (++size <= n)
		jacobCache.push_back(jacobCache[size - 1] + (2 * jacobCache[size - 2]));
	return (jacobCache[n]);
}

void	PmergeMe::parseArg( int ac, char **av )
{
	for (int i = 0; i < ac; i++)
	{
		std::string			arg = av[i];
		std::istringstream	ss(av[i]);
		std::string			token;
		long				value;
		bool                foundNumber = false;

		if (arg.empty())
			throw PmergeMe::ErrorException("Empty argument.");
		while (ss >> token)
		{
			foundNumber = true;
			for (size_t j = 0; j < token.size(); j++)
			{
				if (j == 0 && (token[j] == '+' || token[j] == '-'))
					continue ;
				if (!std::isdigit(static_cast<int>(token[j])))
					throw PmergeMe::ErrorException("Non-digit character found.");
			}
			
			value = std::atol(token.c_str());
			if (value <= 0)
				throw PmergeMe::ErrorException("Input must be a positive integer.");
			else if  (value > std::numeric_limits<int>::max())
				throw PmergeMe::ErrorException("Input overflows.");
			
			_deque.push_back(static_cast<int>(value));
			_vector.push_back(static_cast<int>(value));
		}
		if (!foundNumber)
			throw PmergeMe::ErrorException("Argument contains only whitespace.");
	}
}

std::deque< std::pair<int, int> >	PmergeMe::makePairDeque( const std::deque<int> &deq )
{
	std::deque< std::pair<int, int> >	pairs;

	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		int	a = deq[i];
		int	b = deq[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	return (pairs);
}

std::vector< std::pair<int, int> >	PmergeMe::makePairVector( const std::vector<int> &vec )
{
	std::vector< std::pair<int, int> >	pairs;

	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int	a = vec[i];
		int	b = vec[i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}
	return (pairs);
}

std::deque<int>	PmergeMe::createPendDeque( std::deque< std::pair<int, int> > &pairs, const std::deque<int> &sortedMain )
{
	std::deque<int>	pendChain;

	for (size_t i = 0; i < sortedMain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedMain[i])
			{
				pendChain.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break ;
			}
		}
	}
	return (pendChain);
}


std::vector<int>	PmergeMe::createPendVector( std::vector< std::pair<int, int> > &pairs, const std::vector<int> &sortedMain )
{
	std::vector<int>	pendChain;

	for (size_t i = 0; i < sortedMain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (pairs[j].first == sortedMain[i])
			{
				pendChain.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break ;
			}
		}
	}
	return (pendChain);
}

void	PmergeMe::binarySearchInsertDeque( std::deque<int> &deq, int val )
{
	int	left = 0;
	int right = deq.size();

	while (left < right)
	{
		int	mid = left + (right - left) / 2;

		if (deq[mid] < val)
			left = mid + 1;
		else
			right = mid;
	}
	deq.insert(deq.begin() + left, val);
}

void	PmergeMe::binarySearchInsertVector( std::vector<int> &vec, int val )
{
	int	left = 0;
	int right = vec.size();

	while (left < right)
	{
		int	mid = left + (right - left) / 2;

		if (vec[mid] < val)
			left = mid + 1;
		else
			right = mid;
	}
	vec.insert(vec.begin() + left, val);
}

void	PmergeMe::insertPendDeque( std::deque<int> &mainChain, const std::deque<int> &pendChain )
{
	mainChain.insert(mainChain.begin(), pendChain[0]);

	std::vector<size_t>	jacobSeq;
	size_t	idx = 3;

	while (getJacobsthal(idx) < pendChain.size() - 1)
		jacobSeq.push_back(getJacobsthal(idx++));
	jacobSeq.push_back(pendChain.size() - 1);

	size_t	lastPos = 1;
	for (size_t i = 0; i < jacobSeq.size(); i++)
	{
		size_t	currPos = jacobSeq[i];
		for (size_t j = currPos; j >= lastPos; j--)
		{
			if (j >= pendChain.size())
				continue ;
			binarySearchInsertDeque(mainChain, pendChain[j]);
		}
		lastPos = currPos + 1;
	}
}

void	PmergeMe::insertPendVector( std::vector<int> &mainChain, const std::vector<int> &pendChain )
{
	mainChain.insert(mainChain.begin(), pendChain[0]);

	std::vector<size_t>	jacobSeq;
	size_t	idx = 3;

	while (getJacobsthal(idx) < pendChain.size() - 1)
		jacobSeq.push_back(getJacobsthal(idx++));
	jacobSeq.push_back(pendChain.size() - 1);

	size_t	lastPos = 1;
	for (size_t i = 0; i < jacobSeq.size(); i++)
	{
		size_t	currPos = jacobSeq[i];
		for (size_t j = currPos; j >= lastPos; j--)
		{
			if (j >= pendChain.size())
				continue ;
			binarySearchInsertVector(mainChain, pendChain[j]);
		}
		lastPos = currPos + 1;
	}
}

void	PmergeMe::sortDeque( std::deque<int> &deq )
{
	size_t	size = deq.size();
	
	if (size <= 1)
		return ;
	
	bool	hasRemainder = (size % 2 != 0);
	int		remainder = 0;

	if (hasRemainder)
	{
		remainder = deq.back();
		deq.pop_back();
	}

	std::deque< std::pair<int, int> >	pairs = makePairDeque(deq);
	std::deque<int>						mainChain;
	
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	sortDeque(mainChain);
	
	std::deque<int>	pendChain = createPendDeque(pairs, mainChain);

	insertPendDeque(mainChain, pendChain);
	if (hasRemainder)
		binarySearchInsertDeque(mainChain, remainder);
	deq = mainChain;
}

void	PmergeMe::sortVector( std::vector<int> &vec )
{
	size_t	size = vec.size();
	
	if (size <= 1)
		return ;
	
	bool	hasRemainder = (size % 2 != 0);
	int		remainder = 0;

	if (hasRemainder)
	{
		remainder = vec.back();
		vec.pop_back();
	}

	std::vector< std::pair<int, int> >	pairs = makePairVector(vec);
	std::vector<int>						mainChain;
	
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	sortVector(mainChain);
	
	std::vector<int>	pendChain = createPendVector(pairs, mainChain);

	insertPendVector(mainChain, pendChain);
	if (hasRemainder)
		binarySearchInsertVector(mainChain, remainder);
	vec = mainChain;
}

void	PmergeMe::execute( int ac, char **av )
{
	if (ac < 2)
		throw PmergeMe::ErrorException("No arguments provided.");
	parseArg(ac - 1, av + 1);

	// Deque
	std::cout << std::endl << BLUE "---------" MAGENTA " Deque " BLUE "---------" RESET << std::endl;
	std::cout << YELLOW "Before" RESET ":\t";
	printContainer(_deque);

	std::clock_t	startTimeDeque = std::clock();
	sortDeque(_deque);
	_dequeTime = static_cast<double>(std::clock() - startTimeDeque) / CLOCKS_PER_SEC * 1000.0;

	std::cout << YELLOW "After" RESET ":\t";
	printContainer(_deque);
	std::cout << "Time to process a range of " YELLOW << _deque.size() << RESET " elements with " MAGENTA "std::deque : " GREEN << std::fixed << std::setprecision(5) << getDequeTime() << RESET " ms" << std::endl;
	
	// Vector
	std::cout << std::endl << BLUE "---------" MAGENTA " Vector " BLUE "---------" RESET << std::endl;
	std::cout << YELLOW "Before" RESET ":\t";
	printContainer(_vector);

	startTimeDeque = std::clock();
	sortVector(_vector);
	_vectorTime = static_cast<double>(std::clock() - startTimeDeque) / CLOCKS_PER_SEC * 1000.0;

	std::cout << YELLOW "After" RESET ":\t";
	printContainer(_vector);
	std::cout << "Time to process a range of " YELLOW << _vector.size() << RESET " elements with " MAGENTA "std::vector : " GREEN << std::fixed << std::setprecision(5) << getVectorTime() << RESET " ms" << std::endl;
}

template <typename Container>
void	PmergeMe::printContainer( const Container &container )
{
	for (size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << ' ';
	std::cout << std::endl;
}

PmergeMe::ErrorException::ErrorException( const std::string &msg ) : _msg(RED "Error" RESET ": " + msg) {}

PmergeMe::ErrorException::~ErrorException( void ) throw() {}

const char	*PmergeMe::ErrorException::what( void ) const throw() { return (_msg.c_str()); }
