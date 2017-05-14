#include "TPudge.h"

TPudge::TPudge(size_t XPos, size_t YPos, const std::string& NameSprite)
	: TCreature(XPos, YPos, cocos2d::Sprite::create(NameSprite))
{
}
//random moving
void TPudge::ChopChop() 
{
	int Direct = 100; // by X
	int i = rand()%3;
	switch (i)
	{
		case 0:
		{
			break;
		}
		case 1:
		{
			Direct *= -1;
			break;
		}
		case 2:
		{
			Direct *= 0;
			break;
		}	
	}
	auto moveTo = MoveBy::create(9, Vec2(Direct, -300));
	this->GetModel()->runAction(moveTo);
}
