//
// Created by Raphael Burton on 7/14/21.
//

#include <iostream>
#include <string>
#include <iomanip>

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class Contact
{
	private:
		int	_indx;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	public:
		//constructors
		Contact(); //default constructor
		~Contact();

		//setters
		void	setIndx();
		void	setFirstName();
		void	setLastName();
		void	setNickName();
		void	setPhoneNumber();
		void	setDarkestSecret();

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
		Phonebook(std::string str);
		~Phonebook();
		void toUpperCase();
};

#endif
