#include "phonebook.hpp"

int ft_name_truncated(std::string word)
{
	int len;
	len = 0;
	len = word.length();
	if(len == 10)
		std::cout << word << "|";
	else
	{
		std::string temp;
		temp = word;
		if(len > 10)
		{
			temp.resize(9);
			std::cout << temp << ".|";
		}
		if(len < 10)
		{
			len = 10 - len;
			std::string empty_char(" ");
			while(len > 0)
			{
				std::cout << " ";
				len--;
			}
			std::cout << temp << "|";
		}
	}
	return (0);
}

int check_index(std::string index)
{
	size_t i;
	i = 0;
	while(i < index.length())
	{
		if (index[i] > 47 && index[i] < 58)
			i++;
		else
			return(1);// it is not an integer
	}
	return (0);// it is an integer
}

int get_index(std::string index)
{
	int num;
	num = std::stoi(index);
	if (num > 0 && num < 9)
		return (num);
	return (0);
}

void this_wrong_index()
{
	std::cout << RED << "OH, but I don't have this index!" << SHALLOW << std::endl << std::endl;
}

int main()
{
	class Person person[8];
	std::string command;
	int i = 0, k = 0, m = 1;

	std::cout << BGREEN << "WElCOME to the new and best PHONEBOOK ever! ʕ•́ᴥ•̀ʔ" << SHALLOW << std::endl << std::endl;
	while(m == 1)
	{
		std::cout << "PLEASE, ENTER YOUR COMMAND IN A CAPITAL LETTER: " << GREEN ;
		std::getline(std::cin, command);
		std::cout << SHALLOW;
		if (std::cin.eof())
			return (0);
		if (command.compare("EXIT") == 0)
			return (0);
		else if (command.compare("ADD") == 0)
		{
			if(i < 8)
			{
				person[i].add_contact();
				i++;
			}
			else if (i >= 8)
			{
				std::cout << RED << "OH, your phonebook is full already... "  << SHALLOW << std::endl;
				std::cout << "You can SEARCH or EXIT." << std::endl;
			}
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::cout << "|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾|" << std::endl;
			std::cout << "|     index|first name| last name|  nickname|" << std::endl;
			std::cout << "|__________|__________|__________|__________|" << std::endl;
			k = 0;
			while(k < i)
			{
				std::cout << "|         " << k + 1 << "|";
				ft_name_truncated(person[k].m_first_name);
				ft_name_truncated(person[k].m_last_name);
				ft_name_truncated(person[k].m_nickname);
				std::cout << std::endl;
				std::cout << "|__________|__________|__________|__________|" << std::endl;
				k++;
			}
			std::cout << std::endl;
			std::string index;
			std::cout << "___PLEASE, ENTER THE INDEX: ";
			std::getline(std::cin, index);
			int num;
			if (check_index(index) == 1)// it is not an integer
				this_wrong_index();
			else
			{
				num = get_index(index);
				if (num && num <= i)// it is not an integer
				{
					num--;
					std::cout << "The Person number " << num + 1 << std::endl;
					person[num].print_contact();
				}
				else
					this_wrong_index();
			}
		}
		else
			std::cout << RED <<  "Sorry, I just can SEARCH , ADD or EXIT.. no more..." << SHALLOW << "\n" << std::endl;
		m = 1;
	}
	return (0);
}