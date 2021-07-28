//
// Created by Raphael Burton on 7/14/21.
//
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define RED "\033[1;31m"
# define SHALLOW "\033[0m"
# define BGREEN "\033[7;32m"
# define GREEN "\033[1;32m"
# define BGBLUE "\033[44m"
# define MAGENTA "\033[0;35m"

class Contact
{
	private:
		int	_indx;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
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
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
};

class Phonebook
{
	private:
		Contact _phbk[8];
	public:
		//constructors
		Phonebook();
		//destructors
		~Phonebook();

		//m-methods
		void	addContact();
		void	searchContact();
};

#endif
