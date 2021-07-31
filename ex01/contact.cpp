#include "phonebook.hpp"

//default constructor
Contact::Contact()
	: m_indx(0), m_totalN(0), m_firstName("\0"), m_lastName("\0"), m_nickname("\0"), m_phoneNumber("\0"), m_darkestSecret("\0")
{
	
}

//default destructor
Contact::~Contact() {};

//setters
void	Contact::setIndx(int indx)
{
	m_indx = indx;
	m_totalN++;
}

void	Contact::setFirstName(std::string &firstName)
{
	m_firstName = firstName;
}

void	Contact::setLastName(std::string &lastName)
{
	m_lastName = lastName;
}

void	Contact::setNickname(std::string &nickname)
{
	m_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string &phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string &darkerstSecret)
{
	m_darkestSecret = darkerstSecret;
}

//getters
int	Contact::getIndx()
{
	return (m_indx);
}

int	Contact::getTotalN()
{
	return (m_totalN);
}

std::string	Contact::getFirstName()
{
	return (m_firstName);
}

std::string	Contact::getLastName()
{
	return (m_lastName);
}

std::string	Contact::getNickname()
{
	return (m_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (m_phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (m_darkestSecret);
}

//m-methods
void Contact::printContact()
{
	std::cout << "Contact's index          : " << m_indx << std::endl;
	std::cout << "Contact's first name     : " << m_firstName << std::endl;
	std::cout << "Contact's last name      : " << m_lastName << std::endl;
	std::cout << "Contact's nickname       : " << m_nickname << std::endl;
	std::cout << "Contact's phone number   : " << m_phoneNumber << std::endl;
	std::cout << "Contact's darkest secret : " << m_darkestSecret << std::endl;
}