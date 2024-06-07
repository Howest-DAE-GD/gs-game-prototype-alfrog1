#pragma once
#include <Texture.h>
#include "Player.h"
class PickUpBase
{
public:
	explicit PickUpBase(const Point2f& position, Player* pPlayer);

	virtual ~PickUpBase();

	void Draw();
	bool IsColliding() const;
	void Erase();

	const Player* pPLAYER;

protected:
	Point2f					m_Position;

private:
	
};

