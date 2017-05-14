#pragma once
#include "TSkeleton.h"
class TSkeletonSpear :
	public TSkeleton
{
public:
	TSkeletonSpear(size_t X, size_t Y);
	void Live();
	~TSkeletonSpear();
};

