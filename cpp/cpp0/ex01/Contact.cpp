#include <iostream>
#include <iomanip> 
#include "Contact.hpp"

using std::cin;
using std::cout;
using std::setw;

Contact::Contact() : first_name(""), last_name(""), nickname(""), number(""), secret ("")
{}

Contact::Contact(std::string fname, std::string lname, std::string nick, std::string num, std::string sec):
	first_name(fname), last_name(lname), nickname(nick), number(num), secret(sec)
{}

Contact Contact::fromInput()
{
	std::string first_name, last_name, nickname, number, secret;
	cout << "first name:"; getline(cin, first_name);
	cout << "last name:"; getline(cin, last_name);
	cout << "nickname:"; getline(cin, nickname);
	cout << "phone number:"; getline(cin, number);
	cout << "darkest secret:"; getline(cin, secret);
	return Contact(first_name, last_name, nickname, number, secret);
}

void show_entry(std::string entry)
{
	if(entry.size() > 10)
		cout<<entry.substr(0, 9)<<".";
	else cout<<setw(10)<<entry;
}

void Contact::show()
{
	show_entry(first_name);
	cout<<"|";
	show_entry(last_name);
	cout<<"|";
	show_entry(nickname);
}

void Contact::show_full()
{
	cout<<"------------------------------------------------\n";
	cout<<setw(17)<<"first name :"<<first_name<<"\n";
	cout<<setw(17)<<"last name :"<<last_name<<"\n";
	cout<<setw(17)<<"nickname :"<<nickname<<"\n";
	cout<<setw(17)<<"phone number :"<<number<<"\n";
	cout<<setw(17)<<"darkest secret :"<<secret<<"\n";
	cout<<"------------------------------------------------\n";
}
