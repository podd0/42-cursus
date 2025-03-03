#pragma once
#include "AMateria.hpp"


class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	Cure(const Cure& cure);
	Cure& operator = (const Cure& cure); 
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

};
