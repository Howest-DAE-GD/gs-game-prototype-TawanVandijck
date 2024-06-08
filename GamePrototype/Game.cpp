#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "iostream"
#include "Texture.h"
#include "Camera.h"
#include "Balloon.h"
#include "utils.h"
using namespace utils;


Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Player1 = new Player(Point2f(200.f, 100.f), 20.f, 20.f, Color4f(1.f, 0.f, 0.f, 1.f));
	m_Player2 = new Player(Point2f(400.f, 100.f), 20.f, 20.f, Color4f(1.f, 1.f, 0.f, 1.f));
	m_pBalloon = new Balloon(Point2f(300.f, 420.f), Color4f(0.5f, 0.5f, 0.5f, 1.f));
	m_pBalloon = new Balloon(Point2f(500.f, 420.f), Color4f(1.f, 0.5f, 0.5f, 1.f));
	

}

void Game::Cleanup( )
{
	delete m_Player1;
	delete m_Player2;
	delete m_pBalloon;
	delete m_pBalloon2;
}

void Game::Update( float elapsedSec )
{

	m_Player1->Update(elapsedSec);
	/*m_Player2->Update(elapsedSec);*/
	
	m_pBalloon->GetHit(m_Player1->GetHitBox(), m_Player1->CheckItem());
	/*m_pBalloon2->GetHit(m_Player2->GetHitBox(), m_Player2->CheckItem());*/

	m_Player1->IsOverlap(m_pBalloon->GetHitBox());
	m_Player1->ReplenishOverlap(m_pBalloon->GetReplenishHitBox());
	m_Player1->WeaponOverlap(m_pBalloon->GetKnifeHitBox());
	m_Player1->PlayerWeaponOverlap(m_Player2->GetWeaponHitBox());

	//m_Player2->IsOverlap(m_pBalloon2->GetHitBox());
	//m_Player2->ReplenishOverlap(m_pBalloon2->GetReplenishHitBox());
	//m_Player2->WeaponOverlap(m_pBalloon2->GetKnifeHitBox());
	////m_Player2->PlayerWeaponOverlap(m_Player1->GetWeaponHitBox());
}

void Game::Draw( ) const
{
	ClearBackground( );
	//m_pCamera->Aim2(4000.f, 2239.f, m_Player1->GetPos(), m_Player2->GetPos());
	///*m_pCamera->Aim(4000.f, 2239.f, m_Player1->GetPos());*/
	///*m_pMap->Draw();*/
	
	SetColor(Color4f(0.5f, 0.5f, 0.5f, 1.f));
	FillRect(Point2f(150.f, -150.f), 500, 630);

	m_Player1->Draw();
	m_Player2->Draw();
	m_pBalloon->Draw();
	m_pBalloon2->Draw();
	
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch (e.keysym.sym)
	{
	case SDLK_q:
		m_Player1->Movement(0);
		break;
	case SDLK_d:
		m_Player1->Movement(1);
		break;
	case SDLK_z:
		m_Player1->Movement(2);
		break;
	case SDLK_s:
		m_Player1->Movement(3);
		break;
	case SDLK_LEFT:
		m_Player2->Movement(0);
		break;
	case SDLK_RIGHT:
		m_Player2->Movement(1);
		break;
	case SDLK_UP:
		m_Player2->Movement(2);
		break;
	case SDLK_DOWN:
		m_Player2->Movement(3);
		break;
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	switch (e.keysym.sym)
	{
	case SDLK_q:
		m_Player1->Movement(4);
		break;
	case SDLK_d:
		m_Player1->Movement(5);
		break;
	case SDLK_z:
		m_Player1->Movement(6);
		break;
	case SDLK_s:
		m_Player1->Movement(7);
		break;
	case SDLK_LEFT:
		m_Player2->Movement(4);
		break;
	case SDLK_RIGHT:
		m_Player2->Movement(5);
		break;
	case SDLK_UP:
		m_Player2->Movement(6);
		break;
	case SDLK_DOWN:
		m_Player2->Movement(7);
		break;
	}
	
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	
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

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
