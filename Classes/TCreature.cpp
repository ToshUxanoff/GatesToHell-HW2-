#include <TCreature.h>

#pragma once
#include "cocos2d.h"
USING_NS_CC;

	TCreature::TCreature() : X_coord(0), Y_coord(0)
	{}
	TCreature::TCreature(size_t X, size_t Y, cocos2d::Sprite* Spr) : X_coord(X), Y_coord(Y), Model(Spr)
	{
		Model->setPosition(Vec2(X_coord, Y_coord));
	}

	float TCreature::GetModelWidth()
	{
		return Width;
	}
	float TCreature::GetModelHeight()
	{
		return Height;
	}
	size_t TCreature::GetX()
	{
		return X_coord;
	}
	cocos2d::Sprite * TCreature::GetModel()
	{
		return Model;
	}
	void TCreature::GainX(size_t x)
	{
		X_coord += x;
	}
	void TCreature::GainY(size_t y)
	{
		Y_coord += y;
	}
