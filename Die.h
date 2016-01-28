
#ifndef DIE_H
#define DIE_H

class Die
{
	protected:
		int sides;

	public:
		Die();
		Die(int);
		int roll();
};
#endif