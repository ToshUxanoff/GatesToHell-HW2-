#pragma once
#include "TZombie.h"
//Медленнее ZombieMusic, т.к. не имеет таких крутых наушников и вообще уже засыхает
class TZombieWalker :
	public TZombie 
{	
public:
	TZombieWalker(size_t XPos, size_t YPos);
	void Live();
	~TZombieWalker() = deafult;
}; 
