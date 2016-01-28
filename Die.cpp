
#include "Die.h"
#include "LoadedDie2.h"
#include <cstdlib>

// Constructor
Die::Die()
{
	sides = 0;
}
Die::Die(int dieSides)
{
	sides = dieSides;
}
// Roll Function
int Die::roll()
{
	return rand()% sides + 1;
}


/****************************************************/
// Part of lab 3, ignore for lab 1
LoadedDie2::LoadedDie2()
{
	sides = 0;
}
LoadedDie2::LoadedDie2(int dieSides)
{
	sides = dieSides;
}
int LoadedDie2::rollLoaded()
{
	int roll = rand() % sides + 1;

	return roll + (rand() % sides);
}