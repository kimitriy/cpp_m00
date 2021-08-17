//
// Created by Raphael Burton on 7/14/21.
//

#include "phonebook.hpp"

int		main()
{
	Phonebook book;
	std::string cmnd;

	std::cout << FGRND_B_BLACK << BGRND_CYAN << "WElCOME TO THE PHONEBOOK!" << RESET << std::endl;
	while (1)
	{
		std::cout << FGRND_B_BLACK << BGRND_CYAN << "INPUT ANY COMMAND, PLEASE! USE CAPITAL LETTERS!:" << RESET << " " << FGRND_B_GREEN;
 		std::getline(std::cin, cmnd);
		std::cout << RESET;
		if (std::cin.eof())
			return (0);
		else if (cmnd.compare("ADD") == 0)
			book.addContact();
		else if (cmnd.compare("SEARCH") == 0)
			book.searchContact();
		else if (cmnd.compare("EXIT") == 0)
			return (0);
		else
			std::cout << FGRND_B_BLACK << BGRND_RED << "INPUTED COMMAND HASN'T RECOGNIZED. YOU CAN TRY ANOTHER ONE!" << RESET << std::endl;
	}	
	return (0);
}