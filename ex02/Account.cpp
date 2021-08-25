#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include "Account.hpp"

#define RESET "\033[0m"
#define FGRND_R_BLUE "\033[0;34m"
#define FGRND_R_WHITE "\033[0;37m"

std::string int2str(int num)
{
	std::ostringstream cnvrt;
	cnvrt << num;
	
	return ( cnvrt.str() );
}

//static vars init
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//private constructors
Account::Account( void ) {};

//public constructors
Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << FGRND_R_WHITE << " index:" << FGRND_R_BLUE << _accountIndex << FGRND_R_WHITE << ";amount:" << FGRND_R_BLUE << _amount << RESET << ";created" << std::endl;
}

//public destructors
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << FGRND_R_WHITE << " index:" << FGRND_R_BLUE << _accountIndex << FGRND_R_WHITE << ";amount:" << FGRND_R_BLUE << _amount << RESET << ";closed" << std::endl;
}

//setters

//getters
int	Account::getNbAccounts( void ) //static method for private static m-var
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) //static method for private static m-var
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) //static method for private static m-var
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) //static method for private static m-var
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) //static method
{
	_displayTimestamp();
	std::cout << FGRND_R_WHITE << " accounts:" << FGRND_R_BLUE << Account::getNbAccounts() << FGRND_R_WHITE << ";total:" << FGRND_R_BLUE << Account::getTotalAmount() << FGRND_R_WHITE << ";deposits:" << FGRND_R_BLUE << Account::getNbDeposits() << FGRND_R_WHITE << ";withdrawals:" << FGRND_R_BLUE << Account::getNbWithdrawals() << RESET << std::endl;
}

//private m-methods
void	Account:: _displayTimestamp( void )
{
	time_t rawtime;
	struct tm *tinfo;

	time(&rawtime);
	tinfo = localtime(&rawtime);

	std::string year = int2str(tinfo->tm_year + 1900);
	std::string month;
	month = tinfo->tm_mon < 10 ? month = "0" + int2str(tinfo->tm_mon + 1) : month = int2str(tinfo->tm_mon + 1);
	std::string day;
	day = tinfo->tm_mday < 10 ? day = "0" + int2str(tinfo->tm_mday) : day = int2str(tinfo->tm_mday);
	std::string hour;
	hour = tinfo->tm_hour < 10 ? hour = "0" + int2str(tinfo->tm_hour) : hour = int2str(tinfo->tm_hour);
	std::string min;
	min = tinfo->tm_min < 10 ? min = "0" + int2str(tinfo->tm_min) : min = int2str(tinfo->tm_min);
	std::string sec;
	sec = tinfo->tm_sec < 10 ? sec = "0" + int2str(tinfo->tm_sec) : sec = int2str(tinfo->tm_sec);

	std::cout << "[" << year << month << day << "_" << hour << min << sec << "]";
}

//public m-methods
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << FGRND_R_WHITE << " index:" << FGRND_R_BLUE << _accountIndex << FGRND_R_WHITE << ";amount:" << FGRND_R_BLUE << _amount << FGRND_R_WHITE << ";deposits:" << FGRND_R_BLUE << _nbDeposits << FGRND_R_WHITE << ";withdrawals:" << FGRND_R_BLUE << _nbWithdrawals << RESET << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int		initialAmount = checkAmount();;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_displayTimestamp();
	std::cout << FGRND_R_WHITE << " index:" << FGRND_R_BLUE << _accountIndex << FGRND_R_WHITE << ";p_amount:" << FGRND_R_BLUE << initialAmount << FGRND_R_WHITE << ";deposit:" << FGRND_R_BLUE << deposit << FGRND_R_WHITE << ";amount:" << FGRND_R_BLUE << _amount << FGRND_R_WHITE << ";nb_deposits:" << FGRND_R_BLUE << _nbDeposits << RESET << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int		initialAmount = checkAmount();
	
	if (initialAmount < withdrawal)
	{
		_displayTimestamp();
		std::cout << FGRND_R_WHITE << " index:" << FGRND_R_BLUE << _accountIndex << FGRND_R_WHITE << ";p_amount:" << FGRND_R_BLUE << initialAmount << FGRND_R_WHITE << ";withdrawal:refused" << RESET << std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals += _nbWithdrawals;
		_displayTimestamp();
		std::cout << FGRND_R_WHITE << " index:" << FGRND_R_BLUE << _accountIndex << FGRND_R_WHITE << ";p_amount:" << FGRND_R_BLUE << initialAmount << FGRND_R_WHITE << ";withdrawal:" << FGRND_R_BLUE << withdrawal << FGRND_R_WHITE << ";amount:" << FGRND_R_BLUE << _amount << FGRND_R_WHITE << ";nb_withdrawals:" << FGRND_R_BLUE << _nbWithdrawals << RESET << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	if (_amount > 0)
		return (_amount);
	else
		return (0);
}