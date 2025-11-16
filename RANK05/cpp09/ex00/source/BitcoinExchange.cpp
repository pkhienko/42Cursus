#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void ) { readData(); }

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) { *this = other; }

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &other )
{
	if (this != &other)
		this->_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void ) {}

std::string	BitcoinExchange::trim( const std::string &str )
{
	size_t		start = 0;
	size_t		end = str.size();

	while (start < end && std::isspace(static_cast<int>(str[start])))
		start++;
	while (end > start && std::isspace(static_cast<int>(str[end - 1])))
		end--;
	return (str.substr(start, end - start));
}

void	BitcoinExchange::readData( void )
{
	std::string		filename = "data.csv";
	std::ifstream	file(("data/" + filename).c_str());
	std::string		line;
	
	if (!file.is_open())
		throw BitcoinExchange::CouldNotOpenFileException(filename);

	std::getline(file,  line);
	if (line != COLUMN_DATA)
		throw BitcoinExchange::BadInputColumnException(line, COLUMN_DATA);
	while (std::getline(file, line))
	{
		size_t	commaPos = line.find(",");
		
		if (commaPos == std::string::npos)
			continue ;
		std::string	date = line.substr(0, commaPos);
		std::string	exchange_rate = line.substr(commaPos + 1);
		_data[date] = static_cast<float>(std::atof(exchange_rate.c_str()));
	}
	file.close();
}

void	BitcoinExchange::executeLine( const std::string &line )
{
	std::istringstream	ss(line);
	std::string			date;
	std::string			valueStr;
	float				value;
	std::string			err;

	std::getline(ss, date, '|');
	std::getline(ss, valueStr, '|');
	date = trim(date);
	valueStr = trim(valueStr);
	if (!isValidDate(date))
		throw BitcoinExchange::BadInputDateException(date);
	if (!isValidValue(line, valueStr, value, err))
		throw BitcoinExchange::BadInputException(err);
	calculateValue(date, value);
}


void	BitcoinExchange::calculateValue( const std::string &date, const float &value ) const
{
	std::map<std::string,  float>::const_iterator	iter = _data.lower_bound(date);

	if (iter != _data.end() && iter->first == date)
	{
		std::cout << date << " | " << iter->second << MAGENTA " => " RESET << value << " = " << value * iter->second << std::endl;
		return ;
	}
	if (iter == _data.begin())
		throw BitcoinExchange::BadInputException("Date is too early, no data available" MAGENTA  " => " RESET + date);
	iter--;
	std::cout << date << " | " << iter->second << MAGENTA " => " RESET << value << " = " << value * iter->second << std::endl;
}

bool	BitcoinExchange::isValidDate( const std::string &date )
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	
	std::istringstream	iss(date);
	int					year, month, day;
	char				tmp1, tmp2;

	if (!(iss >> year >> tmp1 >> month >> tmp2 >> day))
		return (false);
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2)
	{
		bool	isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (isLeap ? 29 : 28))
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidValue( const std::string &line, const std::string &valueStr, float &value, std::string &err )
{
	std::istringstream	iss(valueStr);
	std::ostringstream	oss;
	char				c;

	if (!(iss >> value))
	{
		err = "Bad value input" MAGENTA " => " RESET + line;
		return (false);
	}
	if (iss.get(c))
		return (false);
	oss << value;
	if (value < 0)
	{
		err = "Not a positive number" MAGENTA " => " RESET + oss.str();
		return (false);
	}
	else if (value > 1000)
	{
		err = "Too large number" MAGENTA " => " RESET + oss.str();
		return (false);
	}
	return (true);
}

void	BitcoinExchange::run( const std::string &filename )
{
	std::ifstream	file(("data/" + filename).c_str());
	std::string		line;

	if (!file.is_open())
		throw BitcoinExchange::CouldNotOpenFileException(filename);

	std::getline(file, line);
	if (line != COLUMN_INPUT)
		throw BitcoinExchange::BadInputColumnException(line, COLUMN_INPUT);
	while (std::getline(file, line))
	{
		try { executeLine(line); }
		catch(const std::exception &e) { std::cerr << e.what() << std::endl; }
	}
	file.close();
}

BitcoinExchange::BtcException::BtcException( const std::string &msg) : _msg(msg) {}

BitcoinExchange::BtcException::~BtcException( void ) throw() {}

const char	*BitcoinExchange::BtcException::what( void ) const throw() { return (_msg.c_str()); }

BitcoinExchange::CouldNotOpenFileException::CouldNotOpenFileException( const std::string &filename ) : BtcException(RED "Error" RESET ": Could not open file '" + filename + "'") {}

BitcoinExchange::BadInputColumnException::BadInputColumnException( const std::string &err, const std::string &exp ) : BtcException(RED "Error" RESET ": Bad column input => '" + err + "', " GREEN "Expected" RESET ": '" + exp + "'") {}

BitcoinExchange::BadInputDateException::BadInputDateException( const std::string &err ) : BtcException(RED "Error" RESET ": Bad date input" MAGENTA " => " RESET "'" + err + "', " GREEN "Expected" RESET ": 'YYYY-MM-DD'") {}

BitcoinExchange::BadInputException::BadInputException( const std::string &err) : BtcException(RED "Error" RESET ": " + err) {}

