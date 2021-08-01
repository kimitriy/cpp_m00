#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

#define RESET "\033[0m"
#define FGRND_R_BLUE "\033[0;34m"
#define FGRND_R_WHITE "\033[0;37m"

void	err_message(const std::string &err)
{
	std::cout << "Error!" << err << std::endl;
	exit(1);
}

static	int	size(int n)
{
	size_t			i;
	unsigned int	m;

	i = 0;
	m = n;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		m = n * (-1);
		i += 1;
	}
	while (m > 0)
	{
		m /= 10;
		i++;
	}
	return (i);
}

std::string ft_itoa(int n)
{
	std::string		str_cpp;
	char			*arr;
	size_t			c;
	unsigned int	m;

	c = size(n);
	arr = (char *)malloc((c + 1) * sizeof(char));
	if (!arr)
		err_message("Memory allocation error!");
	arr[c] = '\0';
	m = n;
	if (n == 0)
		arr[--c] = '0';
	if (n < 0)
	{
		arr[0] = '-';
		m = -n;
	}
	while (m > 0)
	{
		arr[--c] = ((m % 10) + '0');
		m /= 10;
	}
	str_cpp = static_cast<std::string>(arr);
	return (str_cpp);
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

	std::string year = ft_itoa(tinfo->tm_year + 1900);
	std::string month;
	month = tinfo->tm_mon < 10 ? month = "0" + ft_itoa(tinfo->tm_mon + 1) : month = ft_itoa(tinfo->tm_mon + 1);
	std::string day;
	day = tinfo->tm_mday < 10 ? day = "0" + ft_itoa(tinfo->tm_mday) : day = ft_itoa(tinfo->tm_mday);
	std::string hour;
	hour = tinfo->tm_hour < 10 ? hour = "0" + ft_itoa(tinfo->tm_hour) : hour = ft_itoa(tinfo->tm_hour);
	std::string min;
	min = tinfo->tm_min < 10 ? min = "0" + ft_itoa(tinfo->tm_min) : min = ft_itoa(tinfo->tm_min);
	std::string sec;
	sec = tinfo->tm_sec < 10 ? sec = "0" + ft_itoa(tinfo->tm_sec) : sec = ft_itoa(tinfo->tm_sec);

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