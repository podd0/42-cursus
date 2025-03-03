#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <string> 
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat();
	virtual ~WrongCat();
	WrongCat(const WrongCat& cat);
	WrongCat& operator =(const WrongCat& cat);

	virtual void makeSound() const;

};

#endif