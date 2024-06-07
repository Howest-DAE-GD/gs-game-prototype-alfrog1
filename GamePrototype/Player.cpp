#include "pch.h"
#include "Player.h"
#include <iostream>
#include <Texture.h>
#include "CollisionManager.h"
#include <utils.h>

Player::Player(const Point2f& position) :
		
			 m_Position					{position}
{
	m_pCollisionManager = new CollisionManager(this);
	m_Velocity.x = 50.f;
	m_Velocity.y = 80.f;
}


Player::~Player()
{
	delete m_pCollisionManager;
}

void Player::Draw() const
{
	utils::FillEllipse(m_Position, 4,4);
	//std::cout << m_Position.x << "\t \t" << m_Position.y << "\n";

	//m_pCollisionManager->DrawSVGVertices();
}

void Player::Update(float elapsedSec)
{
	m_pCollisionManager->CheckCollision(elapsedSec);
}

Rectf Player::GetHitbox() const
{
	return Rectf(m_Position.x, m_Position.y, 10,20);
}

void Player::SetLocation(const Point2f& location)
{
	m_Position = location;
}

Circlef Player::GetCharacterCircle()
{
	return Circlef(m_Position, 5);
}

Point2f Player::GetPosition() const
{
	return m_Position;
}

void Player::ResetToStartPos()
{
	Point2f playerStartPos{ 100.f, 62.f };
	m_Position = playerStartPos;
}

void Player::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	Point2f mousePos{ float(e.x), float(e.y) };
	m_Position = mousePos;
}

//void Player::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
//{
//	switch (e.keysym.sym)
//	{
//	case SDLK_a:
//		m_Position.x -= 10;
//		break;
//	case SDLK_d:
//		//std::cout << "`Right arrow key released\n";
//		m_Position.x += 10;
//		break;
//	case SDLK_SPACE:
//		m_Position.y += 10;
//	}
//}
//
//void Player::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
//{
//	switch (e.keysym.sym)
//	{
//	case SDLK_SPACE:
//		m_Position.y += 35;
//		break;
//	}
//}

void Player::Die()
{
	if (m_Position.x >= 1600 && m_Position.y <= 0)
	{
		std::cout << "CONGRATS! You are finally reunited!";
	}
}


