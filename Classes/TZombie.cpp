#include "TZombie.h"

TZombie::TZombie()
{}
TZombie::TZombie(size_t XPos, size_t YPos, const std::string& NameSprite)
	: TCreature(XPos, YPos, cocos2d::Sprite::create(NameSprite))
{}

void TZombie::Live(size_t Time)
{
	auto moveTo = MoveBy::create(Time, Vec2(0, -300));
	this->GetModel()->runAction(moveTo);
}
