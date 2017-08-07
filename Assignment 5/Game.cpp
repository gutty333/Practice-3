#include "Game.h"
#include "StartingRoom.h"
#include "Hallway.h"
#include "Armory.h"
#include "SecurityRoom.h"
#include "LabRoom.h"
#include "CastleTower.h"
#include "Dungeon.h"

// Constructors
Game::Game()
{
	head = NULL;

	player = NULL;
}
Game::Game(Player* p)
{
	player = p;
}

/*
Will set the links of a room to NUll
Also will set the complete to false
This signifies that the current room has not yet been investigated
*/
void Game::setDeafult(room* current)
{
	current->down = NULL;
	current->up = NULL;
	current->left = NULL;
	current->right = NULL;

	current->completed = false;
}

/*
This method will create the map for the game
Each room will be a node that stores a room object and has 4 links
Please refer to the guide to view the map layout
*/
void Game::createMap()
{
	// Creating the room objects
	Room* start = new StartingRoom("Castle Lobby", "This is the entrance to the castle");
	Room* filler = new Hallway("Castle Hallway", "Hallway that is always guarded by a minion");
	Room* armory = new Armory("Armory Room", "This is the armory which is guarded by a nasty cave troll");
	Room* security = new SecurityRoom("Security Room", "This room will reward those that solve the riddle");
	Room* lab = new LabRoom("Laboratory Room", "Here you might find some useful information");
	Room* dungeon = new Dungeon("Dungeon Room", "Hiding room storing a lost artifact");
	Room* end = new CastleTower("Castle Tower", "This is where the princess is located, defeat Suaron and rescue her");

	// Setting up all the rooms in the game;
	head = new room;
	head->currentRoom = start;
	setDeafult(head);

	room* h1 = new room;
	h1->currentRoom = filler;
	setDeafult(h1);
	
	room* h2 = new room;
	h2->currentRoom = filler;
	setDeafult(h2);
	
	room* h3 = new room;
	h3->currentRoom = filler;
	setDeafult(h3);
	
	room* h4 = new room;
	h4->currentRoom = filler;
	setDeafult(h4);
	
	room* h5 = new room;
	h5->currentRoom = filler;
	setDeafult(h5);

	room* h6 = new room;
	h6->currentRoom = filler;
	setDeafult(h6);

	room* h7 = new room;
	h7->currentRoom = filler;
	setDeafult(h7);

	room* h8 = new room;
	h8->currentRoom = filler;
	setDeafult(h8);

	room* h9 = new room;
	h9->currentRoom = filler;
	setDeafult(h9);

	room* secretRoom = new room;
	secretRoom->currentRoom = dungeon;
	setDeafult(secretRoom);

	room* securityRoom = new room;
	securityRoom->currentRoom = security;
	setDeafult(securityRoom);

	room* labRoom = new room;
	labRoom->currentRoom = lab;
	setDeafult(labRoom);

	room* armoryRoom = new room;
	armoryRoom->currentRoom = armory;
	setDeafult(armoryRoom);

	room* tail = new room;
	tail->currentRoom = end;
	setDeafult(tail);

	// Making the connections for the rooms
	head->right = h1;
	h1->left = head;
	h1->right = h2;
	h2->left = h1;
	h2->up = labRoom;
	labRoom->down = h2;
	
	head->left = h6;
	h6->right = head;
	h6->up = h7;
	h7->down = h6;
	h7->right = h8;
	h8->left = h7;
	h8->down = secretRoom;
	secretRoom->up = h8;
	h7->left = h9;
	h9->right = h7;

	head->up = h3;
	h3->down = head;
	h3->right = armoryRoom;
	armoryRoom->left = h3;
	h3->up = securityRoom;
	securityRoom->down = h3;
	securityRoom->right = h4;
	h4->left = securityRoom;
	h4->down = armoryRoom;
	armoryRoom->up = h4;

	h4->up = h5;
	h5->down = h4;
	h5->right = tail;
	tail->left = h5;
}


/*
This method will simulate the flow of the game
Here the player can decide in which direction they like to move
They can interactive with the room
Also here they can view and manage their item
This simulation will continue until the player has died or the player has defeated the final boss
*/
void Game::playGame()
{
	string line;
	line.assign(30, '-');
	int choice;

	// Will simulate the first room
	head->currentRoom->simulate(player);
	head->completed = true;

	// Loop that will dictate the flow of the game
	while (player->getAlive() && !player->getVictory())
	{
		// Action menu where the player can choose what action they would like to do
		cout << endl << "Action Menu" << endl;
		cout << line << endl;
		cout << "1. View Current Room Info" << endl;
		cout << "2. Investigate Current Room" << endl;
		cout << "3. View Stats" << endl;
		cout << "4. View Items" << endl;
		cout << "5. Use Items" << endl;
		cout << "6. Move Up" << endl;
		cout << "7. Move Down" << endl;
		cout << "8. Move Left" << endl;
		cout << "9. Move Right" << endl;
		cin >> choice;

		cout << endl;
		if (choice == 1)
		{
			// Showcases information about the current room
			head->currentRoom->displayRoomInfo();
		}
		else if (choice == 2)
		{
			// Interacts with the current room
			head->currentRoom->simulate(player);

			// Update the status of the current room to completed
			// This is so the player is unable to just skip rooms
			head->completed = true;
		}
		else if (choice == 3)
		{
			// Will show the stats for the player
			player->displayStats();
		}
		else if (choice == 4)
		{
			// Will allow the player to view the items in their inventory 
			player->viewItems();
		}
		else if (choice == 5)
		{
			// Will allow the player to use/read any item
			// This includes switching weapons or armor
			// Reading an item description or using a potion
			player->useItemMenu();
		}
		else if (choice == 6)
		{
			// Will allow the player to move up only if there is a room linked in that direction
			// Also only if this room has been entered
			// In other words you must have entered a room before you can proceed to the next
			if (head->up == NULL)
			{
				cout << "You are unable to move in this direction, please try a different direction" << endl;
			}
			else if (!head->completed)
			{
				cout << "Please investigate the current room before moving to a different room" << endl;
			}
			else
			{
				
				head = head->up;
				cout << "Moving up" << endl;
				
				// Condition to avoid confusion please note that there are multiple castle hallways linked next to each other
				// This does not mean there is an error when you move and see the same name
				// Refer to the guide for clear representation of the map
				if (head->currentRoom->getName() == head->down->currentRoom->getName())
				{
					cout << "You are moving to another " << head->currentRoom->getName() << endl;
				}
				else
				{
					cout << "Your location is now the " << head->currentRoom->getName() << endl;
				}
				
			}
		}
		else if (choice == 7)
		{
			// Will allow the player to move down only if there is a room linked in that direction
			if (head->down == NULL)
			{
				cout << "You are unable to move in this direction, please try a different direction" << endl;
			}
			else if (!head->completed)
			{
				cout << "Please investigate the current room before moving to a different room" << endl;
			}
			else
			{
				head = head->down;
				cout << "Moving down" << endl;

				if (head->currentRoom->getName() == head->up->currentRoom->getName())
				{
					cout << "You are moving to another " << head->currentRoom->getName() << endl;
				}
				else
				{
					cout << "Your location is now the " << head->currentRoom->getName() << endl;
				}
			}
		}
		else if (choice == 8)
		{
			// Will allow the player to move left only if there is a room linked in that direction
			if (head->left == NULL)
			{
				cout << "You are unable to move in this direction, please try a different direction" << endl;
			}
			else if (!head->completed)
			{
				cout << "Please investigate the current room before moving to a different room" << endl;
			}
			else
			{
				head = head->left;
				cout << "Moving left" << endl;
				
				if (head->currentRoom->getName() == head->right->currentRoom->getName())
				{
					cout << "You are moving to another " << head->currentRoom->getName() << endl;
				}
				else
				{
					cout << "Your location is now the " << head->currentRoom->getName() << endl;
				}
			}
		}
		else if (choice == 9)
		{
			// Will allow the player to move right only if there is a room linked in that direction
			if (head->right == NULL)
			{
				cout << "You are unable to move in this direction, please try a different direction" << endl;
			}
			else if (!head->completed)
			{
				cout << "Please investigate the current room before moving to a different room" << endl;
			}
			else
			{
				head = head->right;
				cout << "Moving right" << endl;
				
				if (head->currentRoom->getName() == head->left->currentRoom->getName())
				{
					cout << "You are moving to another " << head->currentRoom->getName() << endl;
				}
				else
				{
					cout << "Your location is now the " << head->currentRoom->getName() << endl;
				}
			}
		}
	}
}