#include "phonebook.hpp"

Person::Person( void ) {
}

Person::~Person( void ){
}

void Person::add_value(std::string *destination, std::string value)//, std::string namestd::string *name
{
	std::string name;
	// std::cout << std::endl;
	std::cout << "Enter your " << value << ": "<< MAGENTA;
	std::getline(std::cin, *destination);
	// std::cin >> *destination;//*name;
	std::cout << SHALLOW;
}

void Person::add_contact()
{
	add_value(&m_first_name, "     first name");//&person,name
	add_value(&m_last_name, "      last name");//&person,name
	add_value(&m_nickname, "       nickname");//&person,name
	add_value(&m_login, "          login");//&person,name
	add_value(&m_postal_address, " postal address");//&person,name
	add_value(&m_email_address, "  email address");//&person,name
	add_value(&m_phone_number, "   phone number");//&person,name
	add_value(&m_birthday_date, "  birthday date");//&person,name
	add_value(&m_favourite_meal, " favourite meal");//&person,name
	add_value(&m_underwear_color, "underwear color");//&person,name
	add_value(&m_darkest_secret, " darkest secret");//&person,name
	std::cout << std::endl;
}

void Person::print_contact()
{
	std::cout << "first name      : " << m_first_name << std::endl;
	std::cout << "last name       : " << m_last_name << std::endl;
	std::cout << "nickname        : " << m_nickname << std::endl;
	std::cout << "login           : " << m_login << std::endl;
	std::cout << "postal address  : " << m_postal_address << std::endl;
	std::cout << "email address   : " << m_email_address << std::endl;
	std::cout << "phone number    : " << m_phone_number << std::endl;
	std::cout << "birthday date   : " << m_birthday_date << std::endl;
	std::cout << "favourite meal  : " << m_favourite_meal << std::endl;
	std::cout << "underwear color : " << m_underwear_color << std::endl;
	std::cout << "darkest secret  : " << m_darkest_secret << std::endl << std::endl;
}