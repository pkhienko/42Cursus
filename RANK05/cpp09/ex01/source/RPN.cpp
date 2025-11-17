#include "RPN.hpp"

RPN::RPN( void ) : _stack(std::stack<int>()) {}

RPN::RPN( const RPN &other ) { *this = other; }

RPN	&RPN::operator=( const RPN &other )
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN( void ) {}

bool	RPN::isOperator( const char &op ) const { return (op == '+'|| op == '-' || op == '*' || op == '/'); }

int	RPN::calculate( int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return  (b + a);
		case '-':
			return  (b - a);
		case '*':
			return  (b * a);
		case '/':
			return  ((a != 0) ? b / a : throw std::runtime_error("Division by zero"));
		default :
			throw std::runtime_error("Invalid operator");
	}
}

void	RPN::execute( const std::string	&expression )
{
	std::stringstream	ss;
	char				token;

	if (expression.empty())
		throw std::runtime_error("Expression is empty");
	ss.str(expression);
	while (ss >> token)
	{
		if (std::isdigit(token))
			_stack.push(token - '0');
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			
			int	a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();

			_stack.push(calculate(a, b, token));
		}
		else
			throw std::runtime_error("Invalid token (operator or operand)");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	std::cout << MAGENTA << "Result" RESET " => " << _stack.top() << std::endl;
}
