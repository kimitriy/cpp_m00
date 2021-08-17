//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"
// #include "utils.hpp"

//default constructor
Phonebook::Phonebook()
	: m_num(0)
{

}

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
			if (m_num < 8)
				m_num++;
			break ;
		}
		else if (m_phbk[i + 1].getIndx() == 0 && i < 7)
		{
			i++;
			m_phbk[i].setIndx(i + 1);
			if (m_num < 8)
				m_num++;
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
	
	std::string mssgs[6] = {
		"Please input a contact's first name!: ",
		"Please input a contact's last name!: ",
		"Please input a contact's nickname!: ",
		"Please input a contact's phone number!: ",
		"Please input a contact's darkest secret!: ",
		"Your input must not be empty! Please, try again!"
	};
	
	int		j = 0;
	int		f = 0;
	std::string tmp;
	
	while (j < 5)
	{
		while (1)
		{
			if (f == 0)
			{
				std::cout << FGRND_R_PURPLE << mssgs[j] << FGRND_R_GREEN;
				std::getline(std::cin, tmp);
				f = 1;
			}
			else
			{
				std::cout << FGRND_R_RED << mssgs[5] << RESET << std::endl;
				std::cout << FGRND_R_PURPLE << mssgs[j] << FGRND_R_GREEN;
				std::getline(std::cin, tmp);
			}
			if (!tmp.empty())
			{
				f = 0;
				break ;
			}
		}
		switch (j)
		{
		case 0:
			m_phbk[i].setFirstName(tmp);
			break;
		case 1:
			m_phbk[i].setLastName(tmp);
			break;
		case 2:
			m_phbk[i].setNickname(tmp);
			break;
		case 3:
			m_phbk[i].setPhoneNumber(tmp);
			break;
		case 4:
			m_phbk[i].setDarkestSecret(tmp);
			break;
		default:
			break;
		}
		j++;
	}
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
	// n = std::stoi(indx);
	n = atoi(indx.c_str());
	if (n <= 0 || n > m_num)
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
	std::cout << FGRND_R_PURPLE << "Please input a contact's index:" << RESET << " " << FGRND_R_GREEN;
	std::getline(std::cin, indx);
	if ((i = validIndex(indx)) > 0)
		m_phbk[i - 1].printContact();
	else
		std::cout << FGRND_B_BLACK << BGRND_RED<< "Index error. Inputed index is not a number or there is no such index." << std::endl;
}