#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = _nbAccounts++;
	this->_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

int	Account::checkAmount( void ) const { return (this->_amount); }

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
		<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:"
		<< _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	char		buffer[20];
	std::time_t now;

	now = time(NULL);
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&now));
	std::cout << "[" << buffer << "] ";
}

void	Account::makeDeposit( int deposit )
{
	if (deposit <= 0)
		return ;
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:"
		<< deposit << ";amount:" << checkAmount() + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal <= 0 || withdrawal > checkAmount())
	{
		std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:"
			<< withdrawal << ";amount:" << checkAmount() - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		return (true);
	}
}
