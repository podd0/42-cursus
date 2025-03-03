#include "Character.hpp"
#include <iostream>
Character::~Character()
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] != 0)
			delete slots[i];
	}
}

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; i++)
		slots[i] = 0;
}

Character::Character(const Character &chara)
{
	*this = chara;
}

Character &Character::operator = (const Character &chara)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
		if (chara.slots[i])
			slots[i] = chara.slots[i]->clone();
		else
			slots[i] = 0;
	}
	name = chara.getName();
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] == 0)
		{
			slots[i] = m;
			// std::cout<<"materia equipped at slot " << i << std::endl;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	slots[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (slots[idx])
		slots[idx]->use(target);
}
