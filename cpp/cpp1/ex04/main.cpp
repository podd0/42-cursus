#include <fstream>
#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of parameters\n";
		return 1;
	}
	Harl harl;

	harl.complain(argv[1]);
}