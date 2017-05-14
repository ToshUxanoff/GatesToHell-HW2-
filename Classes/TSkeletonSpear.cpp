#include "TSkeletonSpear.h"

TSkeletonSpear::TSkeletonSpear(size_t XPos, size_t YPos) : TSkeleton(XPos, YPos, "SkeletonSpear.png")
{}

void TSkeletonSpear::Live()
{
	TSkeleton::CreakCreak(5);
}

TSkeletonSpear::~TSkeletonSpear()
{}
