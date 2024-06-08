#pragma once
#include "utils.h"
#include "Collidable.h"
using namespace utils;


class Ball
{
public:
	Ball(float posX, float posY, float gravity, float maxHeight, Vector2f mouse = Vector2f(100, 100));
	~Ball();

	void Draw();
	void Update(float elapsedSec);
	void SetVertices(std::vector<Point2f>& vertices);
	Vector2f GetPos();

	void ProcessKeyDownEvent(const SDL_KeyboardEvent& e);
	void ProcessKeyUpEvent(const SDL_KeyboardEvent& e);
	void SetRaycast(HitInfo& hitinfo);
	Collidable* GetCollidable() const;

private:

	Vector2f m_Pos;
	Circlef m_Ball{m_Pos.ToPoint2f(), 8.f};
	Vector2f m_TargetPos;
	
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	Vector2f m_Direction;
	float    m_MaxHeight;
	Collidable* m_pCollide{};
	float m_Time{0.f};
	

	Point2f m_RayStart;
	Point2f m_RayEnd;
	std::vector<Point2f> m_Vertices;


	bool m_Left;
	bool m_Right;
	bool m_Up;
	bool m_Down;
};

