#include <iostream>
#include <cctype>

int main( int ac, char *av[] )
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		char	*args;

		av++;
		while (*av)
		{
			args = *av;
			while (*args)
			{
				if (std::isalpha(*args))
					std::cout << (char)std::toupper(*args);
				else
					std::cout << *args;
				args++;
			}
			av++;
		}
		std::cout << std::endl;
	}
	return (0);
}
