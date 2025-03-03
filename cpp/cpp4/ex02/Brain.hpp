#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain{
public:
	std::string ideas[100];
	~Brain();
	Brain();
	Brain(const Brain &brain);
	Brain &operator =(const Brain &brain);
};

#endif