//
// Created by kmtr on 13.07.2021.
//

#include <iostream>
#include <string>

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

class Megaphone
{
	private:
		std::string _str;
	public:
		Megaphone();
		~Megaphone(void);
		void toUpperCase(std::string &str);
};

#endif //EX00_MEGAPHONE_HPP
