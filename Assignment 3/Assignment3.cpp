#include <iostream>
#include <ctime>
#include "Creature.h"
#include "Barbarian.h"
#include "ReptilePeople.h"
#include "BlueMen.h"
#include "Goblin.h"
#include "TheShadow.h"
using namespace std;



int main()
{
	srand(time(0));
	cout << "Welcome to the battlefield" << endl;
	int choice;


	do
	{
		Creature* player = NULL;
		Creature* enemy = NULL;

		// Character selection for the user
		cout << endl << "Please select your character" << endl;
		cout << "1. Barbarian" << endl;
		cout << "2. Reptile People" << endl;
		cout << "3. Blue Men" << endl;
		cout << "4. Goblin" << endl;
		cout << "5. The Shadow" << endl;
		cin >> choice;

		if (choice == 1)
		{
			player = new Barbarian;
		}
		else if (choice == 2)
		{
			player = new ReptilePeople;
		}
		else if (choice == 3)
		{
			player = new BlueMen;
		}
		else if (choice == 4)
		{
			player = new Goblin;
		}
		else if (choice == 5)
		{
			player = new TheShadow;
		}
		
		// Character selection for the enemy
		cout << "Please select the enemy you will face" << endl;
		cout << "1. Barbarian" << endl;
		cout << "2. Reptile People" << endl;
		cout << "3. Blue Men" << endl;
		cout << "4. Goblin" << endl;
		cout << "5. The Shadow" << endl;
		cin >> choice;

		if (choice == 1)
		{
			enemy = new Barbarian;
		}
		else if (choice == 2)
		{
			enemy = new ReptilePeople;
		}
		else if (choice == 3)
		{
			enemy = new BlueMen;
		}
		else if (choice == 4)
		{
			enemy = new Goblin;
		}
		else if (choice == 5)
		{
			enemy = new TheShadow;
		}

		// Fight simulation
		// Both will take turn attacking and defending
		// The loop will stop only when one of the characters have died
		while (player->getAlive() && enemy->getAlive())
		{
			player->combat(enemy);

			if (enemy->getAlive())
			{
				enemy->combat(player);
			}
		}

		// Showcasing the results
		if (player->getAlive())
		{
			cout << endl << "Congratulation you won the battle as a " << player->getName() << endl;
			cout << "Final health for the " << player->getName() << " is " << player->getHealth() << endl;
		}
		else
		{
			cout << endl << "Game over you lost the battle as a "<< player->getName() << endl;
			cout << "Final health for the " << enemy->getName() << " is " << enemy->getHealth() << endl;
		}

		cout << "Thank you for playing" << endl;
		cout << "Try again (1 = yes or 0 = no)" << endl;
		cin >> choice;
	} while (choice != 0);


	return 0;
}