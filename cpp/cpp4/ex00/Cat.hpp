#ifndef CAT_HPP
#define CAT_HPP

#include <string> 
#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& cat);
	Cat& operator =(const Cat& cat);

	virtual void makeSound() const;

};

#endif