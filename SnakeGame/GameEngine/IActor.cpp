#include "IActor.h"



IActor::IActor()
{
}


IActor::~IActor()
{
}

bool IActor::IsActive()
{
	return active;
}

void IActor::SetActive(bool _active)
{
	active = _active;
}
