//
// Created by Raphael Burton on 7/14/21.
//

#include "megaphone.hpp"

//constructor
Megaphone::Megaphone(std::string str)
{
	_str = str;
}

//destructor
Megaphone::~Megaphone() {};

//m-method
void Megaphone::toUpperCase()
{
	int     i;

	i = 0;
	while(_str[i])
	{
		std::cout << static_cast<char>(toupper(_str[i]));
		i++;
	}
}