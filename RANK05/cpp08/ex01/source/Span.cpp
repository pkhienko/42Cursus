#include "Span.hpp"

Span::Span( void ) : _N(0), _vector() {}

Span::Span( unsigned int n ) : _N(n), _vector() { _vector.reserve(n); }

Span::Span( const Span &other ) { *this = other; }

Span	&Span::operator=( const Span &other )
{
	if  (this != &other)
	{
		this->_N = other._N;
		this->_vector = other._vector;
	}
	return (*this);
}

Span::~Span( void ) {}

void	Span::addNumber( int n )
{
	if  (_vector.size() >= _N)
		throw Span::ContainerIsFullException();
	_vector.push_back(n);
}

long		Span::longestSpan( void ) const
{
	if (_vector.size() <= 1)
		throw Span::NoSpanFoundException();

	long	min = *std::min_element(_vector.begin(), _vector.end());
	long	max = *std::max_element(_vector.begin(), _vector.end());
	return (max - min);
}

long		Span::shortestSpan( void ) const
{
	if (_vector.size() <= 1)
		throw Span::NoSpanFoundException();

	t_vector	sort_vector(_vector);
	long		min = MAX_LONG;

	std::sort(sort_vector.begin(), sort_vector.end());
	for (std::size_t i = 1; i < sort_vector.size(); i++)
	{
		long	n = static_cast<long>(sort_vector[i]) - static_cast<long>(sort_vector[i - 1]);
		min = (n < min) ? n : min;
	}
	return (min);
}

void	Span::addNumber( t_vector_iter begin, t_vector_iter end )
{
	if (_vector.size() + std::distance(begin, end) > _N)
		throw Span::ContainerIsFullException();
	_vector.insert(_vector.end(), begin, end);
}

const char	*Span::NoSpanFoundException::what( void ) const throw() { return ("No span can be found"); }

const char	*Span::ContainerIsFullException::what( void ) const throw() { return ("Container is full"); }
