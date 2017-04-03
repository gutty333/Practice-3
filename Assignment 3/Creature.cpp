
#include "Creature.h"
#include "Barbarian.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Goblin.h"
#include "Shadow.h"

// Default Constructor
Creature::Creature()
{
	type = "";
	attackDice = attackSides = defenseSides = defenseDice = health = armor = achilles = 0;
}
// Setter functions
void Creature::updateHealth(int newHealth)
{
	health = newHealth;
}
void Creature::setAchilles(bool specialAttack)
{
	achilles = specialAttack;
}
// Getter Functions
string Creature::getType()
{
	return type;
}
int Creature::getArmor()
{
	return armor;
}
int Creature::getHealth()
{
	return health;
}
int Creature::getAttack()
{
	GameDice diceRoll(attackSides, attackDice);

	return diceRoll.roll();
}
int Creature::getDefense()
{
	GameDice diceRoll(defenseSides, defenseDice);

	return diceRoll.roll();
}
bool Creature::getAchilles()
{
	return achilles;
}


/*******************Barbarian Child*************************/
Barbarian::Barbarian()
{
	type = "Barbarian";
	armor = 0;
	health = 12;
	attackDice = defenseDice = 2;
	attackSides = defenseSides = 6;
}

/*******************Reptile Child*************************/
Reptile::Reptile()
{
	type = "Reptile";
	armor = 7;
	health = 18;
	attackDice = 3;
	defenseDice = 1;
	attackSides = defenseSides = 6;
}

/*******************Blue Men Child*************************/
BlueMen::BlueMen()
{
	type = "Blue Men";
	armor = 3;
	health = 12;
	attackDice = 2;
	defenseDice = 3;
	attackSides = 10;
	defenseSides = 6;
}

/*******************Goblin Child*************************/
Goblin::Goblin()
{
	type = "Goblin";
	armor = 3;
	health = 8;
	attackDice = 2;
	defenseDice = 1;
	attackSides = defenseSides = 6;
	achilles = false;
}

/*******************Shadow Child*************************/
Shadow::Shadow()
{
	type = "Shadow";
	armor = 0;
	health = 12;
	attackDice = 2;
	defenseDice = 1;
	attackSides = 10;
	defenseSides = 6;
}