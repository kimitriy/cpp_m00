//
// Created by Raphael Burton on 7/14/21.
//

#include "megaphone.hpp"

int     main(int argc, char **argv)
{
	std::string str;
	int i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (i < argc)
		{
			str = str + argv[i];
			i++;
		}
		Megaphone blabla(str);
		blabla.toUpperCase();
		std::cout << std::endl;
	}
	return (0);
}