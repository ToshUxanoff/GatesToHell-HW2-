#include "THero.h"

THero::THero(size_t XPos, size_t YPos)
: TCreature(XPos, YPos, cocos2d::Sprite::create(HeroSprite))
{
}
void THero::MoveRight()
{
	GainX(45);
	auto moveTo = MoveBy::create(0.1, Vec2(45, 0));
	this->GetModel()->runAction(moveTo);
}

void THero::MoveLeft()
{
	GainX(-45);
	auto moveTo = MoveBy::create(0.1, Vec2(-45, 0));
	this->GetModel()->runAction(moveTo);
}
void THero::GetDamage(int Damage)
{
	Lifes -= Damage;
}
int THero::GetLifes()
{
	return Lifes;
}
void THero::Heal()
{
	Lifes += 3;
}
