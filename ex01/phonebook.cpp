//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"

//default constructor
Phonebook::Phonebook() {};

//default destructor
Phonebook::~Phonebook() {};

// void Phonebook::addContact(Contact &cntct, int &i)
// {
// 	cntct.setIndx(i);
// 	std::string tmp;
// 	std::cout << "Please input a contact's first name!:";
// 	std::cin >> tmp;
// 	cntct.setFirstName(tmp);
// 	std::cout << "Please input a contact's last name!:";
// 	std::cin >> tmp;
// 	cntct.setLastName(tmp);
// 	std::cout << "Please input a contact's nickname!:";
// 	std::cin >> tmp;
// 	cntct.setNickname(tmp);
// 	std::cout << "Please input a contact's phone number!:";
// 	std::cin >> tmp;
// 	cntct.setPhoneNumber(tmp);
// 	std::cout << "Please input a contact's darkest secret!:";
// 	std::cin >> tmp;
// 	cntct.setDarkestSecret(tmp);
// }

void Phonebook::addContact()
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (_phbk[i].getIndx() == 0)
			_phbk[i].setIndx(i + 1);
		else if (_phbk[i].getIndx() == 8)
		{
			i = 0;
			_phbk[i].setIndx(i + 1);
		}
		std::cout << "Please input a contact's first name!:";
		
		i++;
	}
	
	std::string tmp;
	std::cout << "Please input a contact's first name!:";
	std::getline(std::cin, tmp);
	_phbk[i].setFirstName(tmp);
	std::cout << "Please input a contact's last name!:";
	_phbk[i].setLastName(tmp);
	std::cout << "Please input a contact's nickname!:";
	_phbk[i].setNickname(tmp);
	std::cout << "Please input a contact's phone number!:";
	std::cin >> tmp;
	_phbk[i].setPhoneNumber(tmp);
	std::cout << "Please input a contact's darkest secret!:";
	std::cin >> tmp;
	_phbk[i].setDarkestSecret(tmp);
}

void Phonebook::searchContact()
{
	
}