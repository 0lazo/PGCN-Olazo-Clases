#pragma once
#include<iostream>
//#include Enemy.h
//include Player.h
class Event
{
private:
	int numOfEvents;
	//Enemy* baseEnemy;

public:
	Event();
	~Event();

	void GenerateEvent(//Player& p
	);
	void EnemyEnounter(//Player& p
	);
	void PuzzleEncounter(//Player& p
	);
};

