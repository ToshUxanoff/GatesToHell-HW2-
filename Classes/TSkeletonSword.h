#pragma once
#include "TSkeleton.h"
class TSkeletonSword :
	public TSkeleton
{
public:
	TSkeletonSword(size_t X_Pos, size_t Y_Pos);
	void Live();
	~TSkeletonSword();
};
