#include "Span.hpp"

Span::Span( void ) : _N(0) {}

Span::Span( unsigned int n ) : _N(n) {}

Span::Span( const Span &other )
{
	*this = other;
}

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

long		Span::longestSpan( void )
{
	if (_vector.size() <= 1)
		throw Span::NoSpanFoundException();

	long	min = *std::min_element(_vector.begin(), _vector.end());
	long	max = *std::max_element(_vector.begin(), _vector.end());
	return (max - min);
}

long		Span::shortestSpan( void )
{
	if (_vector.size() <= 1)
		throw Span::NoSpanFoundException();

	t_vector	sort_vector(_vector);
	long		min = MAX_LONG;

	std::sort(_vector.begin(), _vector.end());
	for (unsigned int i = 1; i < _N; i++)
	{
		long	n = static_cast<unsigned int>(sort_vector[i]) - static_cast<unsigned int>(sort_vector[i - 1]);
		min = (n < min) ? n : min;
	}
	return (min);
}

void	Span::addNumber( t_vector_iter begin, t_vector_iter end )
{
	while (_vector.size() + std::distance(begin, end) > _N)
		throw Span::ContainerIsFullException();
	_vector.insert(_vector.begin(), begin, end);
}

const char	*Span::NoSpanFoundException::what( void ) const throw() { return ("No span can be found"); }

const char	*Span::ContainerIsFullException::what( void ) const throw() { return ("Container is full"); }
