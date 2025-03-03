#pragma once
#include "ICharacter.hpp"


class Character : public ICharacter
{
private:
	std::string name;
	AMateria *slots[4];
public:
	virtual ~Character();
	Character(std::string name);
	Character(const Character &chara);
	Character &operator = (const Character &chara);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

};