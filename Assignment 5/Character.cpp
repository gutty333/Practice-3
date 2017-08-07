#include "Character.h"
#include "Player.h"
#include "Troll.h"
#include "Goblin.h"
#include "Orc.h"
#include "Bokoblin.h"
#include "DarkKnight.h"
#include "Wizard.h"
#include "LastBoss.h"

// Default Constructor
Character::Character()
{
	name = "";
	health = attack = defense = 0;
	alive = true;
	turn = true;
}
// Set Name Method
void Character::setName(string n)
{
	name = n;
}
// Set Turn Method
void Character::setTurn(bool update)
{
	turn = update;
}
// Update health Method
void Character::updateHealth(int newHealth)
{
	health = newHealth;

	if (health <= 0)
	{
		alive = false;
	}
}


// Getter Functions
string Character::getName()
{
	return name;
}
bool Character::getAlive()
{
	return alive;
}
bool Character::getTurn()
{
	return turn;
}
int Character::getAttack()
{
	int result = rand() % attack + 1;
	return result;
}
int Character::getDefense()
{
	int result = (rand() % defense + 1) + defense/4;

	return result;
}
int Character::getHealth()
{
	return health;
}

// Display Stats Method
void Character::displayStats()
{
	cout << endl << "Name: " << name << endl;
	cout << "Attack Value Range: 1-" << attack << endl;
	cout << "Defense Value Range: 1-" << defense << endl;
	cout << "Health: " << health << endl;
}


// Fight Method
void Character::fighSimulation(Character* defender)
{
	// Getting attack value from attacker and defense value from defender
	int defenseTotal = defender->getDefense();
	int attackTotal = getAttack();

	cout << endl << name << " will be attacking " << defender->getName() << endl;
	cout << defender->getName() << "'s current health is " << defender->getHealth() << endl;
	cout << name << " got an attack value of " << attackTotal << endl;
	cout << defender->getName() << " got a defense value of " << defenseTotal << endl;

	// Damage value
	int damage = attackTotal  - defenseTotal;

	if (damage <= 0)
	{
		cout << defender->getName() << " will not take damage" << endl;
	}
	else
	{
		cout << defender->getName() << " will take " << damage << " damage points" << endl;
		
		// Updating the health of the defender
		int newHealth = defender->getHealth() - damage;
		defender->updateHealth(newHealth);
	}

	cout << defender->getName() << "'s current health after defending is " << defender->getHealth() << endl;
	
	if (defender->getHealth() <= 0)
	{
		string line;
		line.assign(30, '*');
		cout << endl << line << endl;
		cout << defender->getName() << " has been defeated" << endl;
		cout << line << endl << endl;
	}
}



// Troll Child Constructor
Troll::Troll()
{
	name = "Cave Troll";
	attack = 13;
	defense = 13;
	health = 16;
}
// Goblin Child Constructor
Goblin::Goblin()
{
	name = "Goblin";
	attack = 10;
	defense = 10;
	health = 12;
}
// Orc Child Constructor
Orc::Orc()
{
	name = "Orc";
	attack = 10;
	defense = 12;
	health = 13;
}
// Bokoblin Child Constructor
Bokoblin::Bokoblin()
{
	name = "Bokoblin";
	attack = 10;
	defense = 10;
	health = 12;
}
// Wizard Child Constructor
Wizard::Wizard()
{
	name = "Great Wizard";
	attack = 16;
	defense = 9;
	health = 20;
}
// Dark Knight Child Constructor
DarkKnight::DarkKnight()
{
	name = "Dark Knight";
	attack = 13;
	defense = 15;
	health = 20;
}
// last Boss Child Constructor
LastBoss::LastBoss()
{
	name = "Sauron";
	attack = 15;
	defense = 20;
	health = 50;
}


// Player Child Constructor
Player::Player()
{
	name = "";
	attack = 0;
	defense = 0;
	health = 20;
	victory = false;
}
// Setter methods
void Player::setName(string n)
{
	name = n;
}
void Player::setVictory(bool v)
{
	victory = v;
}

bool Player::getVictory()
{
	return victory;
}


// Will set the attack value for the player based on the weapon they have
void Player::improveAttack(int a)
{
	attack = a;
}
// Will set the defense value for the player based on the armor they have
void Player::improveDefense(int d)
{
	defense = d;
}
// Will increase the health value for the player when they use any healing items
void Player::improveHealth(int h)
{
	health += h;
}
// Add Item method, adding an item to the player inventory
void Player::addItem(Item temp)
{
	playerInventory.addItem(temp);
}
// Remove Item method
void Player::dropItem(string target)
{
	playerInventory.removeItem(target);
}

// Will show the player all the items in their inventory
void Player::viewItems()
{
	cout << endl << "You have a total of " << playerInventory.getSize() << " items in your inventory" << endl;

	cout << "Here are all your current items:" << endl;

	playerInventory.showItems();
}

// Get Inventory Size method
int Player::getInventorySize()
{
	return playerInventory.getSize();
}

// Search item method
// This will be used to determine if a player has a required item needed to certain parts of the game
bool Player::searchItem(string target)
{
	return playerInventory.searchItem(target);
}

// Use item function
// Method will be used to active the default items the player gets at the start
void Player::useItem(Item temp)
{
	if (temp.isArmor())
	{
		// Setting the defense for the player
		improveDefense(temp.getValue());
	}
	else if (temp.isWeapon())
	{
		// Setting the attack for the player
		improveAttack(temp.getValue());
	}
}

// Use item menu function
// Method will can be used anytime during the game 
void Player::useItemMenu()
{
	cout << endl << "Please select which item do you want to use?" << endl;
	playerInventory.showItemMenu();
	int choice;
	cin >> choice;

	Item temp(playerInventory.getItem(choice));

	// Using the item depending on its category
	if (temp.isPerk())
	{
		// Perk Item condition
		cout << "Using a " << temp.getName() << endl;

		// Heal the player
		cout << "This " << temp.getName() << " will increase your health by " << temp.getValue() << " hitpoints" << endl;
		improveHealth(temp.getValue());

		// Removing the item after using it
		dropItem(temp.getName());
	}
	else if (temp.isArmor())
	{
		if (temp.getValue() == defense)
		{
			cout << "You are already using this item as your main armor" << endl;
		}
		else
		{
			cout << "You are now using the " << temp.getName() << " as your main armor" << endl;

			// Update the defense for the player
			improveDefense(temp.getValue());
		}
		
	}
	else if (temp.isWeapon())
	{
		if (temp.getValue() == attack)
		{
			cout << "You are already using this item as your main weapon" << endl;
		}
		else
		{
			cout << "You are now using the " << temp.getName() << " as your main weapon" << endl;

			// Update the attack for the player
			improveAttack(temp.getValue());
		}
	}
	else
	{
		// If the item does not provide any benefits to the player
		// The items will be regarded as an environmental item 
		// These will included door keys, a letter, or a switch to active an operation
		cout << temp.getDescription() << endl;
		cout << "You are unable to utilize this item now" << endl;
		cout << "It does have some other uses, so it is worth keeping for now" << endl;
	}
}