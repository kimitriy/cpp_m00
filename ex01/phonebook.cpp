//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"

Phonebook::Phonebook(std::string str)
{
	_str = str;
}

Phonebook::~Phonebook() {};

void Phonebook::toUpperCase()
{
	int     i;

	i = 0;
	while(_str[i])
	{
		std::cout << static_cast<char>(toupper(_str[i]));
		i++;
	}
}