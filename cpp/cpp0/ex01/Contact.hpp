
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;
public:
	static Contact fromInput();
	Contact();
	Contact(std::string fname, std::string lname, std::string nick, std::string num, std::string sec);
	void show();
	void show_full();

};
void show_entry(std::string entry);

#endif