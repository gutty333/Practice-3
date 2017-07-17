#include "LoadedDie.h"
#include <cstdlib>


// Constructor
LoadedDie::LoadedDie()
{
	sides = 0;
}
LoadedDie::LoadedDie(int dieSides)
{
	sides = dieSides;
}


// Roll Function
int LoadedDie::roll()
{
	int roll = rand() % sides + 1;

	return roll + (rand() % sides);
}
