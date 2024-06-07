#pragma once
#include "PickUpBase.h"
class PickUpsFromStart final: public PickUpBase
{
public:
	explicit PickUpsFromStart(const Point2f& position, Player* pPlayer);
	virtual ~PickUpsFromStart() = default;

private:

};

