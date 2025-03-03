#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Cat();
	const Animal *i = new Dog();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongCat *wrong_cat = new WrongCat();
	const WrongAnimal *ptr = wrong_cat;
	std::cout << wrong_meta->getType() <<" says : "; 
	wrong_meta->makeSound();
	std::cout << std::endl;

	std::cout << wrong_cat->getType() <<" says : "; 
	wrong_cat->makeSound();
	std::cout << std::endl;

	std::cout << wrong_cat->getType() <<", after a cast to WrongAnimal * says : "; 
	ptr->makeSound();
	std::cout << std::endl;
	delete wrong_meta;
	delete wrong_cat;
	Cat cat;
	Animal on_stack = cat;
	Animal &ref = cat;
	std::cout<<std::endl;
	std::cout << "copy of cat to an Animal : ";
	on_stack.makeSound();
	std::cout << "assign cat to an Animal& (no copy, meaning no change in the vptr table) : ";
	ref.makeSound();
	std::cout<<std::endl;
}