#pragma once
#include "TCreature.h"
class TRaii 
{
	TCreature * MonsterPtr = nullptr;
public:
	TRaii() = default;

	void operator=(TCreature * ptr)
	{
		delete MonsterPtr;
		MonsterPtr = ptr;
	}
	~TRaii()
	{
		delete MonsterPtr;
	}

	TCreature& operator*()
	{
		return *MonsterPtr;
	}

	TCreature* operator->()
	{
		return MonsterPtr;
	}

};