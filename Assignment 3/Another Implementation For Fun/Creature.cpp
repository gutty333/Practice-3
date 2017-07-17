#include "Creature.h"
#include "Barbarian.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Goblin.h"
#include "Shadow.h"

// Constructors
Creature::Creature()
{
	type = "";
	health = armor = attackRolls = attackSides= defenseRolls = defenseSides = attackTotal = 0;
}

// Setter Methods}
void Creature::setHealth(int h)
{
	health = h;
}
void Goblin::setAchilles(bool a)
{
	achilles = a;
}

// Getter Methods
string Creature::getType()
{
	return type;
}
int Creature::getHealth()
{
	return health;
}
int Creature::getArmor()
{
	return armor;
}
int Creature::attack()
{
	int total = 0;

	for (int x = 0; x < attackRolls; x++)
	{
		total += rand() % attackSides + 1;
	}
	attackTotal = total;
	return total;
}
int Creature::defense()
{
	int total = 0;

	for (int x = 0; x < defenseRolls; x++)
	{
		total += rand() % defenseSides + 1;
	}
	return total;
}
bool Goblin::getAchilles()
{
	return achilles;
}

// Info Method
void Creature::printInfo()
{
	cout << "Type: " << type << endl;
	cout << "Armor: " << armor << endl;
	cout << "Health: " << health << endl;
}

// Fight Method
void Creature::fight(Creature* attacker, Creature* defender)
{
	int player1 = attacker->attack();
	int player2 = defender->defense();

	cout << attacker->getType() << " has an attack value of " << player1 << endl;
	cout << defender->getType() << " has defense value of " << player2 << endl;
	cout << "Current health of defender is " << defender->getHealth() << endl;

	int damage = player1 - player2;

	if (damage > 0)
	{
		damage -= defender->getArmor();

		cout << "Total damage taken is " << damage << endl;
		if (damage > 0)
		{
			int newHealth = defender->getHealth() - damage;
			defender->setHealth(newHealth);
		}
	}
	cout << "New health of " << defender->getType() << " is " << defender->getHealth() << endl;
}
// Fight Method For Goblin Child
void Goblin::fight(Creature* attacker, Creature* defender)
{
	int player1 = attacker->attack();
	int player2 = defender->defense();

	if (attackTotal == 12 && defender->getType() == "Goblin" && attacker->getType() != "Goblin")
	{
		setAchilles(true);
	}

	if (getAchilles())
	{
		cout << attacker->getType() << " has an attack value of " << player1/2 << " which was cut in half" << endl;
	}
	else
	{
		cout << attacker->getType() << " has an attack value of " << player1 << endl;
	}
	
	cout << defender->getType() << " has defense value of " << player2 << endl;
	cout << "Current health of defender is " << defender->getHealth() << endl;

	int damage = player1 - player2;

	if (damage > 0)
	{
		damage -= defender->getArmor();

		cout << "Total damage taken is " << damage << endl;
		if (damage > 0)
		{
			int newHealth = defender->getHealth() - damage;
			defender->setHealth(newHealth);
		}
	}
	cout << "New health of " << defender->getType() << " is " << defender->getHealth() << endl;
} 
// Fight Method For Shadow Child
void Shadow::fight(Creature* attacker, Creature* defender)
{
	int player1 = attacker->attack();
	int player2 = defender->defense();

	cout << attacker->getType() << " has an attack value of " << player1 << endl;
	cout << defender->getType() << " has defense value of " << player2 << endl;
	cout << "Current health of defender is " << defender->getHealth() << endl;

	int damage = player1 - player2;
	int chance = rand() % 2 + 1;

	if (defender->getType() == "Shadow" && chance == 1)
	{
		damage = 0;
		cout << "\tNo damage will be taken" << endl;
	}
	

	if (damage > 0)
	{
		damage -= defender->getArmor();

		cout << "Total damage taken is " << damage << endl;
		if (damage > 0)
		{
			int newHealth = defender->getHealth() - damage;
			defender->setHealth(newHealth);
		}
	}
	cout << "New health of " << defender->getType() << " is " << defender->getHealth() << endl;
}

// Child/Subclasses Constructors
Barbarian::Barbarian()
{
	type = "Barbarian";
	armor = 0;
	health = 12;
	attackRolls = 2;
	attackSides = 6;
	defenseRolls = 3;
	defenseSides = 6;
}
Reptile::Reptile()
{
	type = "Reptile";
	armor = 7;
	health = 18;
	attackRolls = 3;
	attackSides = 6;
	defenseRolls = 1;
	defenseSides = 6;
}
BlueMen::BlueMen()
{
	type = "BlueMen";
	armor = 7;
	health = 18;
	attackRolls = 3;
	attackSides = 6;
	defenseRolls = 1;
	defenseSides = 6;
}
Goblin::Goblin()
{
	type = "Goblin";
	armor = 3;
	health = 8;
	attackRolls = 2;
	attackSides = 6;
	defenseRolls = 1;
	defenseSides = 6;
	achilles = false;
}
Shadow::Shadow()
{
	type = "Shadow";
	armor = 0;
	health = 12;
	attackRolls = 2;
	attackSides = 10;
	defenseRolls = 1;
	defenseSides = 6;
}