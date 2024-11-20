
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int num_contacts;
public:
	void add();
	void add(Contact c);
	void search();
	PhoneBook();
};
#endif