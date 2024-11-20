#include "PhoneBook.hpp"
#include <iomanip> 
#include <iostream>

using std::cout;
using std::cin;
using std::setw;

void PhoneBook::add(Contact c)
{
	if (num_contacts < 8)
	{
		contacts[num_contacts] = c;
		num_contacts++;
	}
	else
	{
		for(int i = 0; i < 7; i++)
			contacts[i] = contacts[i+1];
		contacts[7] = c;
	}
}

void PhoneBook::add()
{
	add(Contact::fromInput());
}


void PhoneBook::search()
{
	for (int i = 0; i < num_contacts; i++)
	{
		Contact c = contacts[i];
		cout<<setw(10) << i + 1 << "|";
		c.show();
		cout<<"\n";
	}
	int index; cout<<"index:"; cin >> index;
	if (index < 1 || index > num_contacts)
		cout<<"wrong index\n";
	else
	{
		contacts[index-1].show_full();
	}
}

PhoneBook::PhoneBook() : num_contacts(0) {}