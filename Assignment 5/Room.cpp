#include "Room.h"
#include "StartingRoom.h"
#include "Hallway.h"
#include "Armory.h"
#include "SecurityRoom.h"
#include "LabRoom.h"
#include "CastleTower.h"
#include "Dungeon.h"

#include "Troll.h"
#include "Goblin.h"
#include "Orc.h"
#include "Bokoblin.h"
#include "DarkKnight.h"
#include "Wizard.h"
#include "LastBoss.h"


// Constructors
Room::Room()
{
	name = description = "";
}
Room::Room(string n, string d)
{
	name = n;
	description = d;
}

// Getter methods
string Room::getName()
{
	return name;
}
string Room::getDescription()
{
	return description;
}

// Display room info method
void Room::displayRoomInfo()
{
	cout << "Current Room: " << name << endl;
	cout << "Room Description: " <<  description << endl;
}


/*
Starting Room Section
This room will introduce the player to the game objective
Will also provide the player with the default items
*/
StartingRoom::StartingRoom(string n, string d) :Room(n, d) {}

void StartingRoom::simulate(Player* player)
{
	cout << endl << player->getName() <<  " has entered the " << name << endl;

	if (player->getInventorySize() == 0)
	{
		cout << "The villagers have gifted you 3 items to aid you in your search for the princess" << endl;

		Item sword("Soldier's Sword", "Sword crafted from general steel material. Used as the main weapon of choice for the villagers of the mushroom kingdom", 15, false, true, false);
		Item armor("Soldier's Vest", "Vest made from tough leather. Strong enough to deny small strikes from penetrating.", 15, false, false, true);
		Item health("Health Potion", "Health potion which will replenish the vitality of those who drink it.", 7, true, false, false);

		// Adding the default items to the player inventory
		player->addItem(sword);
		player->addItem(armor);
		player->addItem(health);

		// Using the 2 default items that will provide both attack and defense value
		player->useItem(sword);
		player->useItem(armor);
	}
	else
	{
		cout << "Nothing to investigate here" << endl;
	}
}


/*
Hallway Section
This will be a general room that will connect to other more important areas
Can be used as a filler
Generally in this space the player will encounter an enemy they have to battle
*/
Hallway::Hallway(string n, string d) :Room(n, d) {}

void Hallway::simulate(Player* player)
{
	cout << endl << player->getName() << " has entered the " << name << endl;

	// Section that will select a random enemy type each time the player enters this area
	int choice = rand() % 3 + 1;

	Character* enemy;

	if (choice == 1)
	{
		enemy = new Goblin;
	}
	else if (choice == 2)
	{
		enemy = new Orc;
	}
	else
	{
		enemy = new Bokoblin;
	}

	cout << "Warning a/an " << enemy->getName() << " is planning to attack you" << endl;
	cout << "You will enter combat against the " << enemy->getName() << endl;
	cout << endl << "Stats for the " << enemy->getName() << ":";
	enemy->displayStats();

	// Allow the player to select any items, For example they can use a potential before combat to further increase their health
	do
	{
		cout << endl << "Do you want to use any item/s before combat?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;

		if (choice == 1)
		{
			player->useItemMenu();
		}
	} while (choice == 1);
	

	// Section to simulate the combat between the player and the enemy they encounter
	while (player->getAlive() && enemy->getAlive())
	{
		if (player->getTurn())
		{
			player->fighSimulation(enemy);
			player->setTurn(false);
		}
		else
		{
			enemy->fighSimulation(player);
			player->setTurn(true);
		}
	}

	// Condition in the case the player was defeated
	if (!player->getAlive())
	{
		cout << "Game Over" << endl;
		exit(1);
	}
	else
	{
		// Little bonus for the player with regards to item drops
		// There is a 20% chance that the enemy they fight in this area will drop a small healing potion
		choice = rand() % 5 + 1;
		if (choice == 1)
		{
			Item health("Small Health Potion", "Health potion which will replenish the vitality of those who drink it.", 5, true, false, false);
			cout << "The " << enemy->getName() << " dropped a " << health.getName() << endl;
			
			player->addItem(health);
		}


		cout << "Congratulation you won the battle, please continue searching for the princess" << endl;
	}
}


/*
Armory Section
This room will present the player to a much stronger enemy
The room will also award the player with a strong weapon
*/
Armory::Armory(string n, string d) :Room(n, d) {}

void Armory::simulate(Player* player)
{
	cout << endl << player->getName() << " has entered the " << name << endl;

	// Item the player will earn after defeating the enemy in this room
	// Note if the player already has this item, that is a signal that they have already visited this room
	Item sword("Knight's Sword", "Sword crafted from rare steel material. In the right hands this sword can strike any foe with ease", 20, false, true, false);

	// Condition to not have the player repeat the same action when they visit the room again
	if (player->searchItem(sword.getName()))
	{
		cout << "Nothing to investigate here" << endl;
	}
	else
	{
		Character* enemy = new Troll;

		cout << "Warning a/an " << enemy->getName() << " is planning to attack you" << endl;
		cout << "Please be careful this enemy is very powerful and is said to have defeated many past heroes" << endl;
		cout << "You will enter combat against the " << enemy->getName() << endl;
		cout << endl << "Stats for the " << enemy->getName() << ":";
		enemy->displayStats();

		int choice;
		do
		{
			cout << endl << "Do you want to use any item/s before combat?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> choice;

			if (choice == 1)
			{
				player->useItemMenu();
			}
		} while (choice == 1);

		// Section to simulate the combat between the player and the enemy they encounter
		while (player->getAlive() && enemy->getAlive())
		{
			if (player->getTurn())
			{
				player->fighSimulation(enemy);
				player->setTurn(false);
			}
			else
			{
				enemy->fighSimulation(player);
				player->setTurn(true);
			}
		}

		// Condition in the case the player was defeated
		if (!player->getAlive())
		{
			cout << "Game Over" << endl;
			exit(1);
		}
		else
		{
			// Section to reward the player with the new weapon
			cout << "The " << enemy->getName() << " dropped a " << sword.getName() << endl;
			player->addItem(sword);

			cout << "Congratulation you won the battle, please continue searching for the princess" << endl;
		}
	}
}


/*
Security Room Section
For this room the objective of the player is to solve the provided puzzle
The puzzle will involve finding out what the random value is.
They will have 5 attempts, if the go past 5 attempts the alarm will go off and 2 enemies will enter the room
After they either solve the puzzle or defeat the 2 enemies the player can than take the item in this room
There will be a key items which is needed to open the doors to another room
*/
SecurityRoom::SecurityRoom(string n, string d) :Room(n, d) {}

void SecurityRoom::simulate(Player* player)
{
	cout << endl << player->getName() << " has entered the " << name << endl;

	// Item the player will earn after solving the puzzle or defeating the enemies
	// Note if the player already has this item, that is a signal that they have already visited this room
	Item key("Laboratory Key", "Special key used to gain access to the castle's laboratory. This item is found in the security room", 0, false, false, false);
	Item armor("White Knight Armor", "Armor made from steel. Heavy on the body but provides the best protection possible", 20, false, false, true);

	// Again this avoid repeating the simulation if the player revisits this room
	// Here if they have the white armor this implies the players has already entered the laboratory room
	// And in order to enter the laboratory room they must have a key which is only located here in this room
	if (player->searchItem(key.getName()) || player->searchItem(armor.getName()))
	{
		cout << "Nothing to investigate here" << endl;
	}
	else
	{
		cout << "Please solve the puzzle at hand" << endl;
		cout << "Note that you only have 5 tries to guess a number from 1-15" << endl;
		cout << "Do your best, if you set off the alarm enemies will be quick to attack you" << endl;

		int choice;
		int count = 0;
		int num = rand() % 15 + 1;
		
		// Puzzle Section
		while (count < 5)
		{
			cout << endl << "Please guess what the code is. (Enter number from 1-15)" << endl;
			cin >> choice;

			if (choice == num)
			{
				cout << "Wow congratulation you are correct, the code to open the chest was " << num << endl;
				cout << "Here is the laboratory key" << endl;

				player->addItem(key);
				return;
			}

			count++;
			if (5 - count == 0)
			{
				cout << endl << "Warning the alarm has been set, the correct number was " << num << endl;
			}
			else
			{
				cout << "Wrong, please try again you have " << 5 - count << " try/tries left" << endl;
			}
		}
		// The player failed to solve puzzle and now must fight off 2 enemies
		cout << "You must defeat the enemies" << endl;

		Character* enemy =  new Goblin;
		Character* enemy2 = new Orc;

		cout << "Warning a/an " << enemy->getName() << " and a/an " << enemy2->getName() << " are planning to attack you" << endl;
		cout << endl << "Stats for the " << enemy->getName() << " and the " << enemy2->getName() << ":";
		enemy->displayStats();
		enemy2->displayStats();

		cout << endl;
		do
		{
			cout << endl << "Do you want to use any item/s before combat?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> choice;

			if (choice == 1)
			{
				player->useItemMenu();
			}
		} while (choice == 1);


		// Section to simulate the combat between the player and the enemy they encounter
		while (player->getAlive() && enemy->getAlive())
		{
			if (player->getTurn())
			{
				player->fighSimulation(enemy);
				player->setTurn(false);
			}
			else
			{
				enemy->fighSimulation(player);
				player->setTurn(true);
			}
		}

		// Condition in the case the player was defeated
		if (!player->getAlive())
		{
			cout << "Game Over" << endl;
			exit(1);
		}

		while (player->getAlive() && enemy2->getAlive())
		{
			if (player->getTurn())
			{
				player->fighSimulation(enemy2);
				player->setTurn(false);
			}
			else
			{
				enemy2->fighSimulation(player);
				player->setTurn(true);
			}
		}

		// Section after the player has fought both enemies in this room
		if (!player->getAlive())
		{
			cout << "Game Over" << endl;
			exit(1);
		}
		else
		{
			// Here the player will earn the key"
			cout << "Here is the laboratory key" << endl;
			player->addItem(key);

			cout << "Congratulation you won the battle, please continue searching for the princess" << endl;
		}
	}
}


/*
Laboratory Room Section
In order for the player to investigate this room they must have a key which can be found in the security room
If the player has that item in their inventory they can proceed 
This room will just provide them with further information about their objective and reward them with an item
This item will be a new armor
*/
LabRoom::LabRoom(string n, string d) :Room(n, d) {}

void LabRoom::simulate(Player* player)
{
	cout << endl << player->getName() << " has entered the " << name << endl;

	Item key("Laboratory Key", "Special key used to gain access to the castle's laboratory. This is item is found in the security room", 0, false, false, false);
	Item armor("White Knight Armor", "Armor made from steel. Heavy on the body but provides the best protection possible", 20, false, false, true);
	Item letter("Princess' Message", "Princess: Brave warrior I hope you find this message. I am located in the castle tower. Please be careful on your journey, The evil Sauron has some of his best minions guarding the castle tower. I would encourage you to visit the castle dungeon. To get to the castle dungeon, go back to the starting room. Than go left, up, right, and down.", 25, false, false, false);
	
	// Condition to avoid repetitive action
	// We also check if the player has the required item to analyze the room
	if (player->searchItem(armor.getName()))
	{
		cout << "Nothing to investigate here" << endl;
	}
	else if (!player->searchItem(key.getName()))
	{
		cout << "The door to the " << name << " is locked" << endl;
		cout << "Please continue your journey in the castle and locate the proper key to unlock this door" << endl;
		return;
	}
	else
	{
		// Entering the lab section
		cout << "Laboratory door unlocked" << endl;

		// After using the key to open the door the player will drop the item
		player->dropItem(key.getName());

		// Information about your objective
		cout << endl << "There is message on the lab table. Looks like it was written by the princess" << endl;

		cout << "Princess: Brave warrior I hope you find this message. I am located in the castle tower. Please be careful on your journey, The evil Sauron has some of his best minions guarding the castle tower. I would encourage you to visit the castle dungeon to find a legendary weapon. To get to the castle dungeon go back to the starting room; than go left, up, right, and down. Under the laboratory table in this room there is " << armor.getName() << " please use it as it will aid you in the journey. I wish you the best" << endl << endl;

		cout << "You have found the " << letter.getName() << endl;
		player->addItem(letter);

		cout << "You have found the " << armor.getName() << endl;
		player->addItem(armor);
	}
}


/*
Castle Tower Section
This is the last room of the game
The objective here is simple, the player will be confronted by the last boss Sauron and his 2 elite minions
The player has to defeat the enemies to rescue the princess
After fighting the 2 minions the player will proceed to fighting Sauron
The fight will be have some breaks points, to make it more interactive also to also for the player to utilize any resourceful items
The end game will happen after defeating Sauron
*/
CastleTower::CastleTower(string n, string d) :Room(n, d) {}

void CastleTower::simulate(Player* player)
{
	cout << endl << player->getName() << " has entered the " << name << endl;

	Character* lastBoss = new LastBoss;
	Character* enemy = new DarkKnight;
	Character* enemy2 = new Wizard;

	// Fight against the 2 minions found in this room
	cout << "Sauron: Minions take care of the intruder" << endl;
	cout << "Warning a " << enemy->getName() << " and a " << enemy2->getName() << " are planning to attack you" << endl;
	cout << endl << "Stats for the " << enemy->getName() << " and the " << enemy2->getName() << ":";
	enemy->displayStats();
	enemy2->displayStats();

	int choice;
	do
	{
		cout << endl << "Do you want to use any item/s before combat?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;

		if (choice == 1)
		{
			player->useItemMenu();
		}
	} while (choice == 1);

	// Fighting elite enemy 1
	while (player->getAlive() && enemy->getAlive())
	{
		if (player->getTurn())
		{
			player->fighSimulation(enemy);
			player->setTurn(false);
		}
		else
		{
			enemy->fighSimulation(player);
			player->setTurn(true);
		}
	}

	// Condition in the case the player was defeated
	if (!player->getAlive())
	{
		cout << "Game Over" << endl;
		exit(1);
	}

	// Fighting elite enemy 2
	while (player->getAlive() && enemy2->getAlive())
	{
		if (player->getTurn())
		{
			player->fighSimulation(enemy2);
			player->setTurn(false);
		}
		else
		{
			enemy2->fighSimulation(player);
			player->setTurn(true);
		}
	}

	if (!player->getAlive())
	{
		cout << "Game Over" << endl;
		exit(1);
	}
	
	// Fight against Sauron, the last boss
	cout << "Sauron: Fine, I will deal with you myself" << endl;
	cout << "Warning " << lastBoss->getName() << " is planning to attack you" << endl;
	cout << endl << "Stats for the " << lastBoss->getName() << ":";
	lastBoss->displayStats();

	do
	{
		cout << endl << "Do you want to use any item/s before combat?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;

		if (choice == 1)
		{
			player->useItemMenu();
		}
	} while (choice == 1);

	bool midPoint = false;
	while (player->getAlive() && lastBoss->getAlive())
	{
		if (player->getTurn())
		{
			player->fighSimulation(lastBoss);
			player->setTurn(false);
		}
		else
		{
			lastBoss->fighSimulation(player);
			player->setTurn(true);
		}

		// BreakPoint to add some interaction and allow the player to heal up if they have resourceful items
		if (lastBoss->getHealth() <= 25 && !midPoint )
		{
			cout << endl << "Sauron is hurt keep up the fight" << endl << endl;

			do
			{
				cout << "Do you want to use any item/s before combat?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				cin >> choice;

				if (choice == 1)
				{
					player->useItemMenu();
				}
			} while (choice == 1);

			midPoint = true;
		}
	}

	// End game
	if (!player->getAlive())
	{
		cout << "Game Over" << endl;
		exit(1);
	}
	else
	{
		cout << "Congratulation you have defeated the evil Sauron and rescued the Princess" << endl;
		cout << "Thank you for playing" << endl;
		
		// Updating the victory state to signal that the game is over
		player->setVictory(true);
	}
}


/*
Dungeon Room Section
This room will just provide some lore
It will also award the player with a special item
*/
Dungeon::Dungeon(string n, string d) :Room(n, d) {}

void Dungeon::simulate(Player* player)
{
	cout << endl << player->getName() << " has entered the " << name << endl;

	Item sword("Master Sword", "This sword is said to have belong to a legendary warrior. Its shine will spark fear on you foes.", 25, false, true, false);

	if (player->searchItem(sword.getName()))
	{
		cout << "Nothing to investigate here" << endl;
	}
	else
	{
		cout << "You have found the " << sword.getName() << endl;

		cout << "This sword belonged to the previous hero of the mushroom village. Sadly after his defeat to Sauron the sword was hiding away and stored here in the castle dungeon. This weapon is said to have taken out the most feared creatures found in this land. Some say having this weapon is the only way to defeat the evil Sauron. " << endl;

		player->addItem(sword);
	}
}