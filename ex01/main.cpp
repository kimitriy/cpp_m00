//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"

//EXIT, ADD, SEARCH

/*
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
*/

int		main()
{
	Phonebook book;
	std::string cmnd;

	// int	forInstanceInt = 354684513;

	// std::cout << "forInstance: " << ft_itoa(forInstanceInt) << std::endl;

	std::cout << FGRND_B_BLACK << BGRND_CYAN << "WElCOME TO THE PHONEBOOK!" << RESET << std::endl;
	while (1)
	{
		std::cout << FGRND_B_BLACK << BGRND_CYAN << "INPUT ANY COMMAND, PLEASE! USE CAPITAL LETTERS!:" << RESET << " " << FGRND_B_GREEN;
 		std::getline(std::cin, cmnd);
		std::cout << RESET;
		if (std::cin.eof())
			return (0);
		else if (cmnd.compare("ADD") == 0)
			book.addContact();
		else if (cmnd.compare("SEARCH") == 0)
			book.searchContact();
		else if (cmnd.compare("EXIT") == 0)
			return (0);
		else
			std::cout << FGRND_B_BLACK << BGRND_RED << "INPUTED COMMAND HASN'T RECOGNIZED. YOU CAN TRY ANOTHER ONE!" << RESET << std::endl;
	}	
	return (0);
}