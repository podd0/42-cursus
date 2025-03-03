#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"


class MateriaSource : public IMateriaSource
{
private:
	AMateria *slots[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& source);
	MateriaSource &operator = (const MateriaSource& source);
	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};