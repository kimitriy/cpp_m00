//
// Created by Raphael Burton on 7/14/21.
//
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>

# define RESET "\033[0m"

# define FGRND_R_BLACK "\033[0;30m"
# define FGRND_R_RED "\033[0;31m"
# define FGRND_R_GREEN "\033[0;32m"
# define FGRND_R_YELLOW "\033[0;33m"
# define FGRND_R_BLUE "\033[0;34m"
# define FGRND_R_PURPLE "\033[0;35m"
# define FGRND_R_CYAN "\033[0;36m"
# define FGRND_R_WHITE "\033[0;37m"

# define FGRND_B_BLACK "\033[1;30m"
# define FGRND_B_RED "\033[1;31m"
# define FGRND_B_GREEN "\033[1;32m"
# define FGRND_B_YELLOW "\033[1;33m"
# define FGRND_B_BLUE "\033[1;34m"
# define FGRND_B_PURPLE "\033[1;35m"
# define FGRND_B_CYAN "\033[1;36m"
# define FGRND_B_WHITE "\033[1;37m"

# define BGRND_BLACK "\033[7;30m"
# define BGRND_RED "\033[7;31m"
# define BGRND_GREEN "\033[7;32m"
# define BGRND_YELLOW "\033[7;33m"
# define BGRND_BLUE "\033[7;34m"
# define BGRND_PURPLE "\033[7;35m"
# define BGRND_CYAN "\033[7;36m"
# define BGRND_WHITE "\033[7;37m"

// # define BGRND_BLACK="\033[40m"
// # define BGRND_RED="\033[41m"
// # define BGRND_GREEN="\033[42m"
// # define BGRND_YELLOW="\033[43m"
// # define BGRND_BLUE="\033[44m"
// # define BGRND_PURPLE="\033[45m"
// # define BGRND_CYAN="\033[46m"
// # define BGRND_WHITE="\033[47m"

class Contact
{
	private:
		int	m_indx;
		int	m_totalN;
		std::string	m_firstName;
		std::string	m_lastName;
		std::string	m_nickname;
		std::string	m_phoneNumber;
		std::string	m_darkestSecret;
	public:
		//constructors
		Contact(); //default
		//destructors
		~Contact(); //default

		//setters
		void	setIndx(int indx);
		void	setFirstName(std::string &firstName);
		void	setLastName(std::string &lastName);
		void	setNickname(std::string &nickname);
		void	setPhoneNumber(std::string &phoneNumber);
		void	setDarkestSecret(std::string &darkerstSecret);

		//getters
		int	getIndx();
		int	getTotalN();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();

		//m-methods
		void printContact();
};

class Phonebook
{
	private:
		Contact	m_phbk[8];
		int		m_num;
		//private m-methods
		void	truncate(const std::string &str);
		int		validIndex(const std::string &indx);
	public:
		//constructors
		Phonebook();
		//destructors
		~Phonebook();

		//setter

		//getter

		//public m-methods
		void	addContact();
		void	searchContact();
};

#endif
