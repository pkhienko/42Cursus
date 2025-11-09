#include "Iter.hpp"

template <typename T>
void	printElement( const T &e ) { std::cout << e << " "; }

void	subOne( int &i ) { i -= 1; }

void	printString( const std::string &s ) { std::cout << s << " "; }

void	rotOne( std::string &s )
{
	for (std::string::size_type i = 0; i < s.size(); i++)
		s[i] += 1;
}

int main()
{
    std::cout << MAGENTA "--- Int Array ---" RESET << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};

    std::cout << YELLOW "Before " RESET "(Integer): ";
    ::iter(intArray, 5, printElement<int>);
    std::cout << std::endl;
    ::iter(intArray, 5, subOne);
    std::cout << YELLOW "After " RESET "(Integer): ";
    ::iter(intArray, 5, printElement<int>);
    std::cout << std::endl << std::endl;


    std::cout << MAGENTA "--- Float Int Array ---" << std::endl;
    const float constIntArray[] = {10.99, 20.01, 30.1234};

    std::cout << YELLOW "Array " RESET "(Float): ";
    ::iter(constIntArray, 3, printElement<float>);
    std::cout << std::endl << std::endl;

    std::cout << MAGENTA "--- String Array ---" << std::endl;
    std::string strArray[] = {"Hello", "World", "42"};

    std::cout << YELLOW "Before " RESET "(String): ";
    ::iter(strArray, 3, printString);
    std::cout << std::endl;
    ::iter(strArray, 3, rotOne);
	std::cout << YELLOW "After " RESET "(String): ";
    ::iter(strArray, 3, printString);
    std::cout << std::endl << std::endl;

    return (0);
}
