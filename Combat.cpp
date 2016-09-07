
#include <iostream>
#include "Combat.h"
using namespace std;

// Alive member function
// Will verify if the character is alive or dead
bool Combat::alive(Creature* character)
{
	if (character->getHealth() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Fight member function
// Will simulate a fight between two characters
void Combat::fight(Creature* attack, Creature* defend)
{
	if (alive(attack))
	{
		int attackVal = attack->getAttack();
		// Cut there attack by half if the Goblin cut an Achilles Tendon
		if (defend->getAchilles())
		{
			attackVal /= 2;
		}
		int defenseVal = defend->getDefense();
		int damage = attackVal - (defenseVal + defend->getArmor());
		int healthVal = defend->getHealth();

		// Goblin Special Attack
		if (!attack->getAchilles() && attack->getType() == "Goblin" && defend->getType() != "Goblin" && attackVal == 12)
		{
			attack->setAchilles(true);
		}
		// Shadow Special Ability
		int chance = rand() % 2 + 1;
		if (defend->getType() == "Shadow" && chance == 1)
		{
			damage = 0;
			cout << defend->getType() << " special activated which means no damage should be received" << endl;
		}
		if (defend->getAchilles())
		{
			cout << defend->getType() << " special activated " << attack->getType() << " attack value cut in halve" << endl;
		}
		cout << attack->getType() << " attack value: " << attackVal << endl;
		cout << defend->getType() << " defense value: " << defenseVal << endl;
		cout << defend->getType() << " health value: " << healthVal << endl;
		cout << defend->getType() << " armor value: " << defend->getArmor() << endl;
		cout << defend->getType() << " damage take is: " << (damage<0 ? 0:damage) << endl;

		// Apply the damage to the defending character
		if (damage > 0)
		{
			defend->updateHealth(healthVal - damage);
			cout << defend->getType() << " new health value: " << defend->getHealth() << endl;
		}
		cout << endl;

		// Recursion to run the simulation again
		// This time the attacker and defender are switched
		if (alive(defend))
		{
			fight(defend, attack);
		}
		else
		{
			cout << defend->getType() << " has died in battle" << endl;
		}
	}
	else
	{
		cout << attack->getType() << " has died in battle" << endl;
	}
}