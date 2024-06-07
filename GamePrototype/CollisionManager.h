#pragma once
#include <SVGParser.h>
#include <Vector2f.h>

class Player;

class CollisionManager final
{
public:
	explicit CollisionManager(Player* pPlayer);
	virtual ~CollisionManager() = default;

	//SVG COLLISIONS: i have not fully finished my collisions yet
	void CheckVerticalCollision(float elapsedSec);
	void CheckHorizontalCollision();
	void CheckEnemyCollision();
	void CheckCollision(float elapsedSec);

	bool Death();
	void ResetDeathState();

private:

	Player* m_pPlayer;
	Vector2f m_Gravity;
	bool m_IsAlive;


};

