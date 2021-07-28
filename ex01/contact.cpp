#include "phonebook.hpp"

//default constructor
Contact::Contact()
	: _indx(0), _firstName('\0'), _lastName('\0'), _nickname('\0'), _phoneNumber('\0'), _darkestSecret('\0')
{
	
}

//default destructor
Contact::~Contact() {};

//setters
void	Contact::setIndx(int indx)
{
	_indx = indx;
}

void	Contact::setFirstName(std::string &firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(std::string &lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(std::string &nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string &darkerstSecret)
{
	_darkestSecret = darkerstSecret;
}

//getters
int	Contact::getIndx()
{
	return (_indx);
}

std::string	Contact::getFirstName()
{
	return (_firstName);
}

std::string	Contact::getLastName()
{
	return (_lastName);
}

std::string	Contact::getNickName()
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (_darkestSecret);
}