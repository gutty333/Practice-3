#include "Creature.h"
#include "BlueMen.h"
#include "Barbarian.h"
#include "ReptilePeople.h"
#include "Goblin.h"
#include "TheShadow.h"


// Default constructor
Creature::Creature()
{
	name = "";
	type = "";
	teamName = "";
	health = armor = defenseSides = defenseRollCount = attackSides = attackRollCount = alive = killCount = maxHealth = specialAbility =  0;
}

// Get Functions
string Creature::getName()
{
	return name;
}
int Creature::getArmor()
{
	return armor;
}
int Creature::getDefenseSides()
{
	return defenseSides;
}
int Creature::getDefenseRollCount()
{
	return defenseRollCount;
}
int Creature::getAttackSides()
{
	return attackSides;
}
int Creature::getAttackRollCount()
{
	return attackRollCount;
}
int Creature::getHealth()
{
	return health;
}
bool Creature::getAlive()
{
	return alive;
}
bool Creature::getSpecialAbility()
{
	return specialAbility;
}
int Creature::getKillCount()
{
	return killCount;
}
string Creature::getType()
{
	return type;
}
string Creature::getTeamName()
{
	return teamName;
}

// Set Functions
void Creature::setHealth(int newHealth)
{
	health = newHealth;
}
void Creature::setAlive(bool life)
{
	alive = life;
}
void Creature::setName(string CreatureName)
{
	name = CreatureName;
}
void Creature::updateKillCount()
{
	killCount++;
}
void Creature::setTeamName(string n)
{
	teamName = n;
}

// Print stats method
// Will showcase the attributes of the specified creature
void Creature::printStats()
{
	cout << endl <<"\tName: " << name << endl;
	cout << "\tCreature Type: " << type << endl;
	cout << "\tHealth: " << health << endl;
	cout << "\tTotal Kills: " << killCount << endl;
	cout << "\tTeam: " << teamName << endl;
	cout << "\tCurrent Status: " << (alive ? "Alive" : "Dead") << endl;
}

// Health recovery
// Will recover randomly based on the range of their health / 2
// For example if barbarian the creature has a chance to recover from 1-4
void Creature::healthRecovery()
{
	// We check if the creature still has full health
	if (health >= maxHealth)
	{
		cout << "\t" << name << " still has full health, there will be no health recovery" << endl;
		return;
	}

	int limit = health / 2;

	int newHealth = rand() % limit + 1;

	cout << "\t" <<name << " will recover " << newHealth << " strength-point" << endl;
	newHealth += health;
	cout << "\tThe new health for " << name << " is now " << newHealth << endl;

	setHealth(newHealth);
}

// Base combat method
// The object calling the function will take the role of the attacker while the object passed to it is the defender
void Creature::combat(Creature* defender)
{
	cout << endl <<  defender->getName() << " starting health is " << defender->getHealth() << endl;
	

	int attackTotal, defenseTotal;
	attackTotal = defenseTotal = 0;
	
	// Loop to get the attack value
	for (int x = 0; x < attackRollCount; x++)
	{
		attackTotal += rand() % attackSides + 1;
	}

	// Loop to get defense value
	for (int x = 0; x < defender->getDefenseRollCount(); x++)
	{
		defenseTotal += rand() % defender->getDefenseSides() + 1;
	}

	// Condition to implement the special ability from the goblin
	if (defender->getType() == "Goblin" && defender->getSpecialAbility())
	{
		cout << "\t Your attack is being cut in halve due to the special ability from the Goblin" << endl;
		cout << "\t Your original attack of " << attackTotal << " will now be " << attackTotal / 2 << endl;

		// update the attack
		attackTotal /= 2;
	}

	cout << name << " got an attack value of " << attackTotal << endl;
	cout << defender->getName() << " got a defense value of " << defenseTotal << endl;
	
	// Get the difference of the attack and defense
	// Than we analyze if the remaining damage will bypass the armor 
	int damage = attackTotal - defenseTotal;


	// Condition to check if the defender will take damage
	// Will also check if the special ability is activated based on the required conditions
	int chance = rand() % 2;
	if (defender->getType() == "The Shadow" && chance == 1)
	{
		cout << "\tThe Shadow will not take any damage due to its special ability" << endl;
	}
	else if (damage > defender->getArmor())
	{
		damage = damage - defender->getArmor();
		cout << "The damage taken is " << damage << endl;
		cout << "Remember the armor for " << defender->getName() << " is " << defender->getArmor() << endl;
		
		// updating the health of the defender
		int newHealth = defender->getHealth() - damage;
		defender->setHealth(newHealth);

		if (defender->getHealth() <= 0)
		{
			defender->setAlive(false);
		}
	}
	else
	{
		cout << "No damage will be taken" << endl;
		cout << "The armor for " << defender->getName() << " is " << defender->getArmor() << endl;
	}

	cout << defender->getName() << "'s new health is " << defender->getHealth() << endl;
}


// Barbarian Child constructor
Barbarian::Barbarian()
{
	name = "Barbarian";
	type = "Barbarian";
	armor = 0;
	defenseSides = 6;
	defenseRollCount = 2;
	attackSides = 6;
	attackRollCount = 2;
	health = 12;
	maxHealth = 12;
	alive = true;
}

// Reptile People Child constructor
ReptilePeople::ReptilePeople()
{
	name = "Reptile People";
	type = "Reptile People";
	armor = 7;
	defenseSides = 6;
	defenseRollCount = 1;
	attackSides = 6;
	attackRollCount = 3;
	health = 18;
	maxHealth = 18;
	alive = true;
}

// Blue Men Child constructor
BlueMen::BlueMen()
{
	name = "Blue Men";
	type = "Blue Men";
	armor = 3;
	defenseSides = 6;
	defenseRollCount = 3;
	attackSides = 10;
	attackRollCount = 2;
	health = 12;
	maxHealth = 12;
	alive = true;
}

// Goblin Child constructor
Goblin::Goblin()
{
	name = "Goblin";
	type = "Goblin";
	armor = 3;
	defenseSides = 6;
	defenseRollCount = 1;
	attackSides = 6;
	attackRollCount = 2;
	health = 8;
	maxHealth = 8;
	alive = true;
}

// The Shadow Child constructor
TheShadow::TheShadow()
{
	name = "The Shadow";
	type = "The Shadow";
	armor = 0;
	defenseSides = 6;
	defenseRollCount = 1;
	attackSides = 10;
	attackRollCount = 2;
	health = 12;
	maxHealth = 12;
	alive = true;
}



// Goblin combat method
// Will activate his special ability if he gets an attack value of 12
void Goblin::combat(Creature* defender)
{
	cout << endl << "The " << defender->getName() << " starting health is " << defender->getHealth() << endl;

	int attackTotal, defenseTotal;
	attackTotal = defenseTotal = 0;

	// Loop to get the attack value
	for (int x = 0; x < attackRollCount; x++)
	{
		attackTotal += rand() % attackSides + 1;
	}

	// Loop to get defense value
	for (int x = 0; x < defender->getDefenseRollCount(); x++)
	{
		defenseTotal += rand() % defender->getDefenseSides() + 1;
	}

	// Condition to active the special ability for the goblin
	// Will only affect any character except for another Goblin
	if (specialAbility == false && attackTotal == 12 && defender->getType() != type)
	{
		cout << "\tThe Goblin will now be able to cut the Achilles Tendon of " << defender->getName() << endl;
		cout << "\tThe total attack from " << defender->getName() << " will now be cut in halve for the remainder of the combat" << endl;

		// Update the ability
		specialAbility = true;
	}

	cout << "The " << name << " got an attack value of " << attackTotal << endl;
	cout << "The " << defender->getName() << " got a defense value of " << defenseTotal << endl;

	// Get the difference of the attack and defense
	// Than we analyze if the remaining damage will bypass the armor 
	int damage = attackTotal - defenseTotal;

	// Condition to check if the defender will take damage
	int chance = rand() % 2;
	if (defender->getType() == "The Shadow" && chance == 1)
	{
		cout << "\tThe Shadow will not take any damage due to its special ability" << endl;
	}
	else if (damage > defender->getArmor())
	{
		damage = damage - defender->getArmor();
		cout << "The damage taken is " << damage << endl;
		cout << "Remember the armor for " << defender->getName() << " is " << defender->getArmor() << endl;

		// updating the health of the defender
		int newHealth = defender->getHealth() - damage;
		defender->setHealth(newHealth);

		if (defender->getHealth() <= 0)
		{
			defender->setAlive(false);
		}
	}
	else
	{
		cout << "No damage will be taken" << endl;
		cout << "The armor for the " << defender->getName() << " is " << defender->getArmor() << endl;
	}

	cout << "The " << defender->getName() << "'s new health is " << defender->getHealth() << endl;
}