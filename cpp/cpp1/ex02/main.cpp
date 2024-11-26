#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string: " << &str << "\n";
	std::cout << "Address inside the pointer: " << stringPTR << "\n";
	std::cout << "Address inside the reference: " << &stringREF << "\n";

	std::cout << "The string: " << str << "\n";
	std::cout << "The string, accessed from the pointer: " << *stringPTR << "\n";
	std::cout << "The string, accessed from the reference: " << stringREF << "\n";

}