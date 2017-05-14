#include "TZombieWalker.h"

TZombieWalker::TZombieWalker(size_t XPos, size_t YPos) : TZombie(XPos, YPos, "ZS.png")
{
}
void TZombieWalker::Live() 
{
	TZombie::Live(12);
}
