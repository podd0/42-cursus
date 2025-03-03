#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string> 

class WrongAnimal
{
protected:
	std::string type;
	WrongAnimal(std::string type);
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& animal);
	WrongAnimal operator =(const WrongAnimal& animal);

	std::string getType() const;
	void makeSound() const;

};

#endif