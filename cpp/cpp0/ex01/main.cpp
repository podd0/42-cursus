
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phonebook;
	while(true)
	{
		std::string choice, _;
		std::cout<<"type SEARCH, ADD or EXIT:";
		std::cin >> choice;
		getline(std::cin, _);
		if(choice == "ADD")
			phonebook.add();
		else if(choice == "SEARCH")
			phonebook.search();
		else if(choice == "EXIT")
			break;
		else std::cout<<"Option '"<<choice<<"' does not exist\n";
	}
}