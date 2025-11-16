#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <sstream>
# include <fstream>
# include <iostream>
# include <algorithm>
# include <exception>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define MAGENTA "\033[1;35m"

# define COLUMN_DATA "date,exchange_rate"
# define COLUMN_INPUT "date | value"

class BitcoinExchange {
	private :
		std::map<std::string, float>	_data;

		// Method
		void		readData( void );
		std::string	trim( const std::string &str );
		void		executeLine( const std::string &line );
		bool		isValidDate( const std::string &date );
		void		calculateValue( const std::string &date, const float &value ) const;
		bool		isValidValue( const std::string &line, const std::string &valueStr, float &value, std::string &err );

	public :
		// Constructors
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &other );

		// Operators Overload
		BitcoinExchange	&operator=( const BitcoinExchange &other );

		// Destructor
		~BitcoinExchange( void );

		// Method
		void	run( const std::string &filename );

		// Base Class Exception
		class BtcException : public std::exception {
			protected :
				std::string	_msg;

			public :
				BtcException( const std::string &msg );

				virtual ~BtcException( void ) throw();

				virtual const char	*what( void ) const throw();
		};

		// Exception
		class CouldNotOpenFileException : public BtcException {
			public :
				CouldNotOpenFileException( const std::string &filename );
		};

		class BadInputColumnException : public BtcException {
			public :
				BadInputColumnException( const std::string &err, const std::string &exp );
		};

		class BadInputDateException : public BtcException {
			public :
				BadInputDateException( const std::string &err );
		};

		class BadInputException : public BtcException {
			public :
				BadInputException( const std::string &err );
		};
};

#endif
