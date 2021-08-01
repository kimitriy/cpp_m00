#include "phonebook.hpp"
// #include "utils.hpp"

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
	std::cout << FGRND_R_PURPLE << "Contact's index          : " << FGRND_R_GREEN << m_indx << std::endl;
	std::cout << FGRND_R_PURPLE << "Contact's first name     : " << FGRND_R_GREEN << m_firstName << std::endl;
	std::cout << FGRND_R_PURPLE << "Contact's last name      : " << FGRND_R_GREEN << m_lastName << std::endl;
	std::cout << FGRND_R_PURPLE << "Contact's nickname       : " << FGRND_R_GREEN << m_nickname << std::endl;
	std::cout << FGRND_R_PURPLE << "Contact's phone number   : " << FGRND_R_GREEN << m_phoneNumber << std::endl;
	std::cout << FGRND_R_PURPLE << "Contact's darkest secret : " << FGRND_R_GREEN << m_darkestSecret << std::endl;
}