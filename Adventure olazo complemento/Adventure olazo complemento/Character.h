#pragma once
class Character
{
private:
public:
	void TakeDamage(int d);
	const int DoDamage();
	bool IsAlive();
	int GetLevel() { return this->level; }
};

