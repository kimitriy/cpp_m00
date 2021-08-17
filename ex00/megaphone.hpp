//
// Created by Raphael Burton on 7/14/21.
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
		Megaphone(std::string str);
		~Megaphone();
		void toUpperCase();
};

#endif //EX00_MEGAPHONE_HPP
