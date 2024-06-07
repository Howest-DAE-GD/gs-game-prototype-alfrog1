#pragma once
#include <Texture.h>
#include "CollisionManager.h"
class Player final
{
public:
	explicit Player(const Point2f& position);

	virtual ~Player();

	void Draw() const;
	void Update(float elapsedSec);

	void ResetToStartPos();
	void ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e);

	void Die();

	//Getters and setters
	Rectf	GetHitbox() const;
	Point2f GetPosition() const;
	void	SetLocation(const Point2f& location);
	Circlef GetCharacterCircle();


	//Constants

private:
	CollisionManager* m_pCollisionManager;

	Vector2f	m_Velocity;
	Point2f		m_Position;
	Rectf characterbox;
};

