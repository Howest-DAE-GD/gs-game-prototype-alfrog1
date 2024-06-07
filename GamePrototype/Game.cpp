#include "pch.h"
#include "Game.h"
#include <utils.h>
#include <iostream>
using namespace utils;
using namespace std;

Game::Game( const Window& window ) 
	:BaseGame{ window }, 
	m_BottomVertices{ Rectf{100,200,80,100},
	Rectf{  100, 320,  140, 110},
	Rectf{ 120, 80,  55, 85},
	Rectf{ 110, 0, 70, 55},
	Rectf{ 100, 460,  60, 48},
	Rectf{ 200, 0,  46, 292},
	Rectf{ 180, 450,  122, 270},
	Rectf{ 260, 300,  82, 32},
	Rectf{ 260, 360,  121, 59},
	Rectf{ 270, 0,  126, 90},
	Rectf{ 415, 0,  69, 206},
	Rectf{500, 0,  60, 95},
	Rectf{270, 110,  72, 170},
	Rectf{355, 150,  42, 58},
	Rectf{355, 225,  51, 116},
	Rectf{315, 435,  101, 86},
	Rectf{420, 225,  81, 86},
	Rectf{435, 325,  111, 86},
	Rectf{395, 360,  25, 46},
	Rectf{357, 105,  35, 26},
	Rectf{435, 478,  101, 86},
	Rectf{500, 110,  65, 76},
	Rectf{520, 203,  40, 106},
	Rectf{435, 427,  81, 36},



	},
	m_IsAlive{true}
	, m_Started{false}
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_pPlayer = new Player(Point2f{ m_PlayerStartPos });
	m_pPickUpFromStart1 = new PickUpsFromStart(Point2f(190,305), m_pPlayer);
	m_pPickUpFromStart2 = new PickUpsFromStart(Point2f{345,290 }, m_pPlayer);
	m_pPickUpFromStart3 = new PickUpsFromStart(Point2f{420, 340 }, m_pPlayer);
	m_pPickUpFromStart4 = new PickUpsFromStart(Point2f(255, 435), m_pPlayer);
	m_pPickUpFromStart5 = new PickUpsFromStart(Point2f{ 405,211 }, m_pPlayer);
	m_pPickUpFromStart6 = new PickUpsFromStart(Point2f{ 510, 315 }, m_pPlayer);
	m_pPickUpFromStart7 = new PickUpsFromStart(Point2f{ 413, 272 }, m_pPlayer);
	m_pFont = new Texture("Click to start", "prstartk.ttf", 10, Color4f(1.f, 1.f, 1.f, 1.f));

	OutputText();
}

void Game::Cleanup( )
{
	delete m_pPlayer;
	delete m_pPickUpFromStart1;
	delete m_pPickUpFromStart2;
	delete m_pPickUpFromStart3;
	delete m_pPickUpFromStart4;
	delete m_pPickUpFromStart5;
	delete m_pPickUpFromStart6;
	delete m_pPickUpFromStart7;

}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
	m_pPlayer->Update(elapsedSec);
	CheckCollision();
}

void Game::Draw( ) const
{
	ClearBackground( );


	//m_pCamera->Aim(float(m_pBackground->GetWidth()), float(m_pBackground->GetHeight()), m_pPlayer->GetPosition());

	//for (std::vector<Point2f> vec :  m_Vertices)
	std::cout << int(m_pPlayer->GetPosition().x) << "\t" << int(m_pPlayer->GetPosition().y) << std::endl;
	//{
	if (m_Started)
	{
		if (m_IsAlive)
		{
			SetColor(Color4f(0.f, 0.5f, 0.f, 1.f));
			for (int idx{ 0 }; idx < m_BottomVertices.size(); ++idx)
			{
				FillRect(m_BottomVertices[idx]);
			}
			//}

			SetColor(Color4f(1.f, 0.78f, 0.78f, 1.f));
			m_pPlayer->Draw();
			DrawEllipse(1750, 100, 5, 10);
			FillEllipse(Point2f(610, 240), 4, 4);

			SetColor(Color4f(1.f, 0.f, 1.f, 1.f));

			m_pPickUpFromStart1->Draw();
			m_pPickUpFromStart2->Draw();
			m_pPickUpFromStart3->Draw();
			m_pPickUpFromStart4->Draw();
			m_pPickUpFromStart5->Draw();
			m_pPickUpFromStart6->Draw();
			m_pPickUpFromStart7->Draw();

		}
		else
		{
			SetColor(Color4f(1.f, 0.f, 0.f, 1.f));
			FillRect(0, 0, GetViewPort().width, GetViewPort().height);
		}

	}
	else {
		SetColor(Color4f(0.f, 0.f, 0.f,1.f));
		FillRect(0, 0, GetViewPort().width, GetViewPort().height);
		m_pFont->Draw(Point2f(int(GetViewPort().width / 2 - 80), int(GetViewPort().height / 2 - 10)));
		SetColor(Color4f(1.f, 1.f, 1.f, 1.f));
		DrawRect(Rectf(50, GetViewPort().height / 2-10, 20, 20));
	}
	
	
	//m_pCamera->Reset();

	//std::cout << float(m_pPlayer->GetPosition().x) << "\t" << float(m_pPlayer->GetPosition().y) << "\n";
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
	//m_pPlayer->ProcessKeyDownEvent(e);

}

void Game::ProcessKeyUpEvent(const SDL_KeyboardEvent& e )
{
	//m_pPlayer->ProcessKeyUpEvent(e);
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
	if (m_Started)	m_pPlayer->ProcessMouseMotionEvent(e);
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	Point2f mouse{ float(e.x), float(e.y) };
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		if (!m_Started) {
			if (IsPointInRect(mouse, Rectf(50, GetViewPort().height / 2, 20, 20))) {
				m_Started = true;
			}
		}
		else return;
		break;
	}


}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::OutputText() const {
	cout << std::endl << "An ancient, forgotten experiment went horribly wrong, triggering a series of disasters. \n" <<
		"The apocalypse hit upon this world, and everyone around you has been brainwashed, and is out to kill you. \n" <<
		"You are the only person who hasn't been affected by the brainwashing, or so you thought... \nAs it turns out, there is another person who also hasn't been affected. \n \n" <<
		"To find the other person, you have to collect all the materials needed to save the world first. \nBut be careful, because just touching the people could be enough to end you! \n \n";
	
}

void Game::CheckCollision()
{
	for (Rectf rect : m_BottomVertices)
	{
		if (IsOverlapping(rect, m_pPlayer->GetCharacterCircle()))
		{
			m_IsAlive = false;
			std::cout << "YOU LOSE!!!! \n";
		}
	}
}
