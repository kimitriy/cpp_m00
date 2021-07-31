//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"

//default constructor
Phonebook::Phonebook() {};

//default destructor
Phonebook::~Phonebook() {};

//setter


//getter


void Phonebook::addContact()
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (m_phbk[i].getIndx() == 0)
		{
			m_phbk[i].setIndx(i + 1);
			break ;
		}
		else if (m_phbk[i + 1].getIndx() == 0 && i < 7)
		{
			i++;
			m_phbk[i].setIndx(i + 1);
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
	
	std::cout << FGRND_R_PURPLE << "Please input a contact's first name!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setFirstName(tmp);

	std::cout << FGRND_R_PURPLE << "Please input a contact's last name!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setLastName(tmp);

	std::cout << FGRND_R_PURPLE << "Please input a contact's nickname!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setNickname(tmp);

	std::cout << FGRND_R_PURPLE << "Please input a contact's phone number!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setPhoneNumber(tmp);

	std::cout << FGRND_R_PURPLE << "Please input a contact's darkest secret!: " << FGRND_R_GREEN;
	std::getline(std::cin, tmp);
	m_phbk[i].setDarkestSecret(tmp);

}

void Phonebook::truncate(const std::string &str)
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

int	Phonebook::validIndex(const std::string &indx)
{
	int i = 0;
	int	n = indx.length();

	while (i < n)
	{
		if (indx[i] > 47 && indx[i] < 58)
			i++;
		else
			return (-1);
	}
	n = std::stoi(indx);
	if (n <= 0 || n > 8)
		return (-1);
	return (n);
}

void Phonebook::searchContact()
{
	std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;

	int i = 0;
	while (i < 8)
	{
		if (m_phbk[i].getIndx() != 0)
		{
			std::cout << "|         " << m_phbk[i].getIndx() << "|";
			truncate(m_phbk[i].getFirstName());
			truncate(m_phbk[i].getLastName());
			truncate(m_phbk[i].getNickname());
			std::cout << std::endl;
			std::cout << "|__________|__________|__________|__________|" << std::endl;
		}
		i++;
	}
	std::cout << std::endl;
	std::string	indx;
	std::cout << BGRND_CYAN << "Please input a contact's index: " << FGRND_R_GREEN;
	std::getline(std::cin, indx);
	if ((i = validIndex(indx)) > 0)
		m_phbk[i - 1].printContact();
	else
		std::cout << BGRND_CYAN << "Index error. Inputed index is not a number or there is no such index." << std::endl;
}