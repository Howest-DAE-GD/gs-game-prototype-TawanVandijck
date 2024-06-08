#include "pch.h"
#include "Game.h"
#include "Ball.h"
#include "utils.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "ObstacleBall.h"
#include "ObstacleSpawner.h"
#include <iostream>
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

void Game::Initialize()
{
	m_Ball = new Ball{ 435.f, 250.f, -30.f, 400 };

	m_Vertices.push_back(Point2f(-50, 200));
	m_Vertices.push_back(Point2f(250, 50));
	m_Vertices.push_back(Point2f(650, 50));
	m_Vertices.push_back(Point2f(900, 200));
	m_Vertices.push_back(Point2f(900, -10));
	m_Vertices.push_back(Point2f(-50, -10));

	m_pCollisionManager = new CollisionManager();
	m_Ball->SetVertices(m_Vertices);
	m_pCamera = new Camera{ GetViewPort().width, GetViewPort().height };
	m_pObstacleBall = new ObstacleBall{ 300.f, -300.f, 40.f, 30.f };
	m_pObstacleSpawner = new ObstacleSpawner{ 600.f, 1400.f, 70.f };
	m_pObstacleSpawner->SetCollisionManager(m_pCollisionManager);
	m_pCollisionManager->AddCollidable(m_Ball->GetCollidable());
	m_pCollisionManager->AddCollidable(m_pObstacleBall->GetCollidable());
}

void Game::Cleanup( )
{


	delete m_pCollisionManager;
	delete m_pObstacleSpawner;
	delete m_pObstacleBall;
	delete m_pCamera;
	delete m_Ball;

	m_pCollisionManager = nullptr;
	m_pObstacleSpawner = nullptr;
	m_pObstacleBall = nullptr;
	m_pCamera = nullptr;
	m_Ball = nullptr;

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

	m_Ball->Update(elapsedSec);
	/*m_pObstacleBall->Update(elapsedSec);*/
	m_pObstacleSpawner->Update(elapsedSec, m_Ball->GetPos());
	m_CameraHeight += 150.f * elapsedSec;
	/*std::cout << m_CameraHeight << std::endl;*/
	m_pCollisionManager->CheckCollision();

}

void Game::Draw( ) const
{
	ClearBackground( );
	m_pCamera->Aim(GetViewPort().width, m_Ball->GetPos().y + 600, Point2f(m_Ball->GetPos().ToPoint2f().x, m_CameraHeight));
	

	SetColor(Color4f(0.f, 1.f, 0.f, 1.f));
	m_Ball->Draw();
	m_pObstacleBall->Draw();
	m_pObstacleSpawner->Draw();
	

	m_pCamera->Reset();

}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
	m_Ball->ProcessKeyDownEvent(e);
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	m_Ball->ProcessKeyUpEvent(e);
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
	
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << " right button " << std::endl;
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << " middle button " << std::endl;
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
