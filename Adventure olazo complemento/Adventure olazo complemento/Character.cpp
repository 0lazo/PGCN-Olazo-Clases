#include "Character.h"

void Character::TakeDamage(int d)
{
	//this->hp -= d ;
}

const int Character::DoDamage()
{
	//return (rand() % (this->damageMax - this->damageMin + 1)) + this->damageMin;
}

bool Character::IsAlive()
{
	return (this->hp > 0);
}
