#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}
void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}



void Harl::complain( std::string level )
{
	enum Harl::levels levels[4] = {DEBUG, INFO, WARNING, ERROR};
	static const std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	enum Harl::levels level_type = NONE;

	for(int i = 0; i < 4; i++)
	{
		if (level == names[i])
		{
			level_type = levels[i];
			break;
		}
	}
	switch (level_type)
	{
		case NONE:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
		case DEBUG:
			std::cout << "[DEBUG]\n";
			debug();
			std::cout << "\n";
		case INFO:
			std::cout << "[INFO]\n";
			info();
			std::cout << "\n";
		case WARNING:
			std::cout << "[WARNING]\n";
			warning();
			std::cout << "\n";
		case ERROR:
			std::cout << "[ERROR]\n";
			error();
	}
}
