#include "TSkeletonSword.h"

TSkeletonSword::TSkeletonSword(size_t XPos, size_t YPos) : TSkeleton(XPos, YPos, "SkeletonFast.png")
{}

void TSkeletonSword::Live()
{
	TSkeleton::CreakCreak(3);
}

TSkeletonSword::~TSkeletonSword()
{
}
