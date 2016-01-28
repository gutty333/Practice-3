// Child of the Die class
// This will be used for lab 3

#ifndef LOADEDDIE2_H
#define LOADEDDIE2_H
#include "Die.h"

class LoadedDie2: public Die
{
	public:
		LoadedDie2();
		LoadedDie2(int);
		int rollLoaded();
};

#endif