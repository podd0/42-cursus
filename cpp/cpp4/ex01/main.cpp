#include <iostream>
#include "Cat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *arr[100];
	for(int i = 0; i < 50; i++)
		arr[i] = new Dog();
	for(int i = 50; i < 100; i++)
		arr[i] = new Cat();
	
	for(int i = 0; i < 100; i++)
		delete arr[i];
	
}