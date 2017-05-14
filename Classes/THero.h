#pragma once
#include <string>
#include "TCreature.h"

const std::string HeroSprite = "HeroSprite.png";
class THero 
	: public TCreature
{
	int Lifes = 10;
	
public: 
	THero(size_t XPos, size_t YPos);	
	~THero() = default;
	void MoveRight();
	void MoveLeft();
	void GetDamage(int Damage);
	
	int GetLifes();
	void Heal();
};
