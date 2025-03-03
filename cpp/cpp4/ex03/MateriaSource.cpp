#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		slots[i] = 0;
}
MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i])
		{
			delete slots[i];
		}
	}
}
MateriaSource::MateriaSource(const MateriaSource& source)
{
	*this = source;
}
MateriaSource &MateriaSource::operator = (const MateriaSource& source)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i])
			delete slots[i];
		if (source.slots[i])
			slots[i] = source.slots[i]->clone();
		else 
			slots[i] = 0;
	}
	return *this;
}
void MateriaSource::learnMateria(AMateria* m)
{
	for(int i = 0; i < 4; i++)
	{
		if (slots[i] == 0)
		{
			slots[i] = m;
			return ;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (slots[i] && type == slots[i]->getType())
			return slots[i]->clone();
	}
	return NULL;
}
