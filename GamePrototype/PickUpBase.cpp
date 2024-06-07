#include "pch.h"
#include "PickUpBase.h"
#include <utils.h>
using namespace utils;

PickUpBase::PickUpBase(const Point2f& position, Player* pPlayer): m_Position{position}, pPLAYER{pPlayer}
{
}

PickUpBase::~PickUpBase()
{
	
}

void PickUpBase::Draw() 
{
	FillRect(m_Position, 3, 3);

	if (IsColliding())
	{
		PickUpBase::Erase();
	}
}

bool PickUpBase::IsColliding() const 
{
	const float width{ 10 };
	const float height{ 10 };
	const Rectf pickUpHitbox{ m_Position.x, m_Position.y, width, height };

	return utils::IsOverlapping(pickUpHitbox, pPLAYER->GetHitbox());
}

void PickUpBase::Erase()
{
	m_Position.y = -400;
}



