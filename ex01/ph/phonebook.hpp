#include <iostream>
#include <string>
#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
#define RED "\033[1;31m"
#define SHALLOW "\033[0m"
#define BGREEN "\033[7;32m"
#define GREEN "\033[1;32m"
#define BGBLUE "\033[44m"
#define MAGENTA "\033[0;35m"

class Person{
// private:
public:
	std::string	m_first_name ;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_login;
	std::string	m_postal_address;
	std::string	m_email_address;
	std::string	m_phone_number;
	std::string	m_birthday_date;
	std::string	m_favourite_meal;
	std::string	m_underwear_color;
	std::string	m_darkest_secret;

	Person ( void );
	~Person ( void );
	void add_value(std::string *destination, std::string value);
	void add_contact();
	void print_contact();
};
#endif
