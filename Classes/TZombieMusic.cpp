#include "TZombieMusic.h"



TZombieMusic::TZombieMusic(size_t XPos, size_t YPos) : TZombie(XPos, YPos, "ZSMusic.png")
{}

void TZombieMusic::Live()
{
	TZombie::Live(6);
}

TZombieMusic::~TZombieMusic()
{
}
