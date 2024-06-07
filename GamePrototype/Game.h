#pragma once
#include "BaseGame.h"
#include "Player.h"
#include "CollisionManager.h"
#include "PickUpsFromStart.h"
#include "Background.h"
#include <Texture.h>
class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;
	void OutputText() const;
	void CheckCollision();

	// DATAMEMBERS

	Player* m_pPlayer;
	PickUpsFromStart* m_pPickUpFromStart1;
	PickUpsFromStart* m_pPickUpFromStart2;
	PickUpsFromStart* m_pPickUpFromStart3;
	PickUpsFromStart* m_pPickUpFromStart4;
	PickUpsFromStart* m_pPickUpFromStart5;
	PickUpsFromStart* m_pPickUpFromStart6;
	PickUpsFromStart* m_pPickUpFromStart7;


	Background* m_pBackground;

	//Point2f m_PlayerStartPos{ 100, 62 };
	Point2f m_PlayerStartPos{ 50, 150 };
	Point2f m_TestDiamondPos{ 530, 130 };
	std::vector<Rectf> m_BottomVertices;
	std::vector<Rectf> m_TopVertices;
	bool m_IsAlive;
	bool m_Started;
	Texture* m_pFont;
};