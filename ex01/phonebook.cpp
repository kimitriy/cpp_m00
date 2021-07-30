//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"

//default constructor
Phonebook::Phonebook()
{
	m_n = 0;
	m_totalN = 0;
}

//default destructor
Phonebook::~Phonebook() {};

//setter
// void Phonebook::setN(int n)
// {
// 	m_n = n;
// }

// void Phonebook::setTotalN(int n)
// {
// 	m_totalN = n;
// }

//getter
// int	Phonebook::getN()
// {
// 	return (m_n);
// }

// int	Phonebook::getTotalN()
// {
// 	return (m_totalN);
// }

void Phonebook::addContact()
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (m_phbk[i].getIndx() == 0)
		{
			m_phbk[i].setIndx(i + 1);
			m_n = i + 1;
			break ;
		}
		else if (m_phbk[i + 1].getIndx() == 0 && i < 7)
		{
			i++;
			m_phbk[i].setIndx(i + 1);
			m_n = i + 2;
			break ;
		}
		else if (i == 7 && m_phbk[i].getIndx() != 0)
		{
			i = 0;
			m_phbk[i].setIndx(i + 1);
			break ;
		}
		else if (m_phbk[i].getIndx() != 0 && m_phbk[i + 1].getIndx() != 0 && m_phbk[i].getTotalN() > m_phbk[i + 1].getTotalN())
		{
			i++;
			m_phbk[i].setIndx(i + 1);
			break ;
		}
		i++;
	}
	
	std::string tmp;
	
	std::cout << BGRND_CYAN << "Please input a contact's first name!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setFirstName(tmp);

	std::cout << BGRND_CYAN << "Please input a contact's last name!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setLastName(tmp);

	std::cout << BGRND_CYAN << "Please input a contact's nickname!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setNickname(tmp);

	std::cout << BGRND_CYAN << "Please input a contact's phone number!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setPhoneNumber(tmp);

	std::cout << BGRND_CYAN << "Please input a contact's darkest secret!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setDarkestSecret(tmp);

}

void Phonebook::truncate(std::string &str)
{
	int	len;
	len = str.length();
	if (len < 10)
	{
		int	indnt;
		indnt = 10 - len;
		while (indnt > 0)
		{
			std::cout << " ";
			indnt--;
		}
		std::cout << str << "|";
	}
	else if (len == 10)
		std::cout << str << "|";
	else if (len > 10)
	{
		std::string tmp;
		tmp = str;
		tmp.resize(9);
		std::cout << tmp << ".|";
	}
}

void Phonebook::searchContact()
{
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;


}