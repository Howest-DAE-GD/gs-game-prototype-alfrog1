#include "pch.h"
#include "CollisionManager.h"
#include <utils.h>
#include <iostream>
#include "Player.h"
using namespace utils;

CollisionManager::CollisionManager(Player* pPlayer) :
	m_pPlayer{ pPlayer }, m_IsAlive{ true }
	//m_IsColliding{false}
{
	//CollisionManager::LoadSVG("SVG.svg");
	
	m_Gravity.y = 50.f;
	
}

void CollisionManager::CheckCollision(float elapsedSec)
{
	CheckVerticalCollision(elapsedSec);
	CheckHorizontalCollision();
}

bool CollisionManager::Death()
{
	m_pPlayer->GetPosition().y <= 0 ? m_IsAlive = false : m_IsAlive = true;
	return m_IsAlive;
}

void CollisionManager::ResetDeathState()
{
	m_IsAlive = true;
}

void CollisionManager::CheckVerticalCollision(float elapsedSec)
{

	//HitInfo floorRaycastResult1;
	//HitInfo floorRaycastResult2;
	//
	//const Rectf hitbox{ m_pPlayer->GetHitbox() };
	//
	//const Point2f bottom{ m_pPlayer->GetPosition().x ,m_pPlayer->GetPosition().y - 10};
	//const Point2f top{ m_pPlayer->GetPosition().x ,m_pPlayer->GetPosition().y + 10 };
	//	
	//if		(Raycast(m_BottomMap, bottom, top, floorRaycastResult1))	m_pPlayer->SetLocation(Point2f{ 0,0 });
	//
	//else	m_pPlayer->SetLocation(Point2f{ hitbox.left, hitbox.bottom - m_Gravity.y * elapsedSec });
	//
	//
	//HitInfo floorRaycastResult3;
	//HitInfo floorRaycastResult4;
	//
	//if (Raycast(m_TopMap, bottom, top, floorRaycastResult2))	m_pPlayer->SetLocation(Point2f{ 0,0 });
	//
	//else	m_pPlayer->SetLocation(Point2f{ hitbox.left, hitbox.bottom - m_Gravity.y * elapsedSec });

}

void CollisionManager::CheckHorizontalCollision()
{

	//HitInfo horizontalRaycastResult1{};
	//HitInfo horizontalRaycastResult2{};
	//
	//const Rectf hitbox{ m_pPlayer->GetHitbox() };
	//
	//if (Raycast(m_BottomMap, Point2f{ hitbox.left, hitbox.bottom + hitbox.height / 2 }, Point2f{ hitbox.left + hitbox.width, hitbox.bottom + hitbox.height / 2}, horizontalRaycastResult1)) {
	//	if (horizontalRaycastResult1.lambda >= 0) m_pPlayer->SetLocation(Point2f(horizontalRaycastResult1.intersectPoint.x - hitbox.width, hitbox.bottom));
	//	else if (horizontalRaycastResult1.lambda <= 1) m_pPlayer->SetLocation(Point2f(horizontalRaycastResult1.intersectPoint.x, hitbox.bottom));
	//}
	//
	//
	//HitInfo horizontalRaycastResult3{};
	//HitInfo horizontalRaycastResult4{};
	//
	//if (Raycast(m_TopMap, Point2f{ hitbox.left, hitbox.bottom + hitbox.height / 2 }, Point2f{ hitbox.left + hitbox.width, hitbox.bottom + hitbox.height / 2 }, horizontalRaycastResult1)) {
	//	if (horizontalRaycastResult1.lambda >= 0) m_pPlayer->SetLocation(Point2f(horizontalRaycastResult1.intersectPoint.x - hitbox.width, hitbox.bottom));
	//	else if (horizontalRaycastResult1.lambda <= 1) m_pPlayer->SetLocation(Point2f(horizontalRaycastResult1.intersectPoint.x, hitbox.bottom));
	//}
}

void CollisionManager::CheckEnemyCollision()
{
	
}



