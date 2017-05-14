#pragma once

#include "TCreature.h"
USING_NS_CC;
class TPudge :
	public TCreature
{
public:
	TPudge(size_t XPos, size_t YPos, const std::string& NameSprite);
	void ChopChop();
};
