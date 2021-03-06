#pragma once
#include "cocos2d.h"
#include <vld.h>
USING_NS_CC;

class TCreature
{
	cocos2d::Sprite* Model;
	size_t X_coord;
	size_t Y_coord;
	float Width = Model->getContentSize().width;
	float Height = Model->getContentSize().height;
public:
	TCreature();
	TCreature(size_t X, size_t Y, cocos2d::Sprite* Spr);
	~TCreature() = default;
	float GetModelWidth();
	float GetModelHeight();

	size_t GetX();
	cocos2d::Sprite * GetModel();

	void GainX(size_t x);
	void GainY(size_t y);
	virtual void Live();
	virtual void ChopChop();
	virtual void CreakCreak();

};
