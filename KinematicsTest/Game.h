#pragma once
#include "BaseGame.h"
#include "Ball.h"
#include "Camera.h"
#include "CollisionManager.h"
#include "ObstacleBall.h"
#include "ObstacleSpawner.h"
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

	Ball* m_Ball{};
	std::vector<Point2f> m_Vertices;
	Camera* m_pCamera{};
	ObstacleBall* m_pObstacleBall{};
	ObstacleSpawner* m_pObstacleSpawner{};
	float    m_CameraHeight{0.f};
	CollisionManager* m_pCollisionManager;

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;
};