#pragma once
#include "TCreature.h"
class TSkeleton :
	public TCreature
{
public:
	TSkeleton();
	TSkeleton(size_t XPos, size_t YPos, const std::string& NameSprite);
	~TSkeleton() = default;
	void CreakCreak(size_t Time); 
};
