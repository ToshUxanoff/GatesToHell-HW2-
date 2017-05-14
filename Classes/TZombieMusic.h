#pragma once
#include "TZombie.h"
// Он быстрее ZombieWalker благодаря стильным наушникам и крутой музыке
class TZombieMusic :
	public TZombie
{
public:

	TZombieMusic(size_t XPos, size_t YPos);
	void Live();
	~TZombieMusic();
};

