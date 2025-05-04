#include <iostream>
#include <fstream>
#include <string>

static bool	open_file( std::string filename, std::ifstream &infile, std::ofstream &outfile )
{
	std::string	ofile_name = filename + ".replace";

	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return (false);
	}
	outfile.open(ofile_name.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		infile.close();
		return (false);
	}
	return (true);
}

static void	replace_all( std::string &s1, std::string &s2, std::ifstream &infile, std::ofstream &outfile )
{
	std::string				res;
	std::string				line;
	std::string::size_type	s1_len = s1.length();

	while (std::getline(infile, line))
	{
		for (std::string::size_type i = 0; i < line.length();)
		{
			if (s1_len > 0 && line.substr(i, s1_len) == s1)
			{
				res += s2;
				i += s1_len;
			}
			else
			{
				res += line[i];
				i++;
			}
		}
		outfile << res << '\n';
		res.clear();
	}
}

int	main( int ac, char **av )
{
	std::string		filename;
	std::string		s1;
	std::string		s2;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (ac != 4)
	{
		std::cout << "Error: Invalid argument" << std::endl;
		std::cout << "Usage: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = av[1];
	s1 = av[2];
	if (s1.empty())
	{
		std::cout << "Error: S1 is empty" << std::endl;
		return (1);
	}
	s2 = av[3];
	if (s2.empty())
	{
		std::cout << "Error: S2 is empty" << std::endl;
		return (1);
	}
	if (!open_file(filename, infile, outfile))
		return (1);
	replace_all(s1, s2, infile, outfile);
	infile.close();
	outfile.close();
	return (0);
}