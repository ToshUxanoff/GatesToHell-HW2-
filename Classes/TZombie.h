#pragma once
#include <TCreature.h>
USING_NS_CC;

class TZombie : 
	public TCreature
{
public:
	TZombie();
	~TZombie() = default;
	TZombie(size_t XPos, size_t YPos, const std::string& NameSprite);
	void Live(size_t Time);
};
