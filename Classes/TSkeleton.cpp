#include "TSkeleton.h"

TSkeleton::TSkeleton()
{}
TSkeleton::TSkeleton(size_t XPos, size_t YPos, const std::string& NameSprite)
	: TCreature(XPos, YPos, cocos2d::Sprite::create(NameSprite))
{}
//move to random coords by x
void TSkeleton::CreakCreak(size_t Time)
{
	int Direct = 180; // by X
	int i = rand() % 200;
	auto moveTo = MoveTo::create(Time, Vec2(Direct + i, 0));
	this->GetModel()->runAction(moveTo);
}
