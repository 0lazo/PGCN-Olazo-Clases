#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

void Event::GenerateEvent(//Player& p
)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 10;
	switch (i)
	{
	case 7:
		std::cout << "Keep Travelling..." << std::endl;
		break;
	case 5:
	    std::cout << "Puzzle Encounter" << std::endl;
		break;
	default:
		std::cout << "Enemy Encounter" << std::endl;
		EnemyEnounter(p);
		break;
	}
}

void Event::EnemyEnounter(//Player& p
)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	bool escape = false;
	bool playerTurn = false;
	bool playerDefending = false;
	int firstTurn = rand() % 100 + 1;
	if (firstTurn >= 50 /* - p->GetLuck()*/)
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	std::cout << "----- New Enemy Encounter -----" << std::endl;

	int level = p.GetLevel();
	int hp = level * 10;
	int damageMin = (rand() % level + 1);
	int damageMax = (rand() % level + 1 ) * 2;
	int currentDamage = rand() / (damageMax - damageMin + 1);
	int defense = rand() % level;
	int exp = level * 10;
	//baseEnemy = new Enemy("", level,hp,exp,currentDamage,defense);
	//Ordenar como esten puestos en Enemy.h^

	while (!playerDefeated || !enemyDefeated || !escape)
	{
		int escapeRand = 0;
		int attackRoll = 0;
		if (playerTurn)
		{
			std::cout << "Choose your action" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Stats" << std::endl;
			std::cout << "4: Enemy Stats" << std::endl;
			std::cout << "0: Escape" << std::endl;

			std::cin >> choice;
			switch (choice)
			{
			case 0:
				int escapeRand = (rand() % 100);// +p.GetLuck
				if (escapeRand > 25)
				{
					std::cout << "Escaped..." << std::endl;
					escape = true;
				}
				break;
			case 1:
				std::system("cls");
				int attackRoll = rand() % 12 + 1;
				if (attackRoll > (50 -/* p.*/))
				{
					std::cout << "Player hit Enemy" << std::endl;
					//baseEnemy->TakeDamage(p.DoDamage());
				}
				break;
			case 2:
				playerDefending = true;
				break;
			case 3:
				//p.printPlayerStets();
				break;
			case 4:
				//baseEnemy->printStats();
				break;
			default:
				std::cout << "Invalid Option" << std::endl;
				break;

			}
			playerTurn = false;
		}
		else
		{
			std::cout << "-----ENEMT TURN-----" << std::endl;
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy Defeated" << std::endl;
				std::cout << "Exp: " << baseEnemy.getExp() << std::endl;
			}
			else
			{
				attackRoll = rand() % 100 + 1;
				if (playerDefending)
				{
					if (attackRoll >75)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.takeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;
					}
				}
				else
				{
					if (attackRoll > 45)
					{
						std::cout << "Enemy hit Player" << std::endl;
						p.takeDamage(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;
					}
				}
			}
			playerTurn = true;
		}
	}
}

void Event::PuzzleEncounter()
{
}
