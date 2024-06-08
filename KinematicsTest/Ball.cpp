#include "pch.h"
#include "Ball.h"
#include "utils.h"
#include "Collidable.h"
#include <iostream>
using namespace utils;




Ball::Ball(float posX, float posY, float gravity, float maxHeight, Vector2f mouse):
    m_Pos(posX, posY), m_TargetPos(mouse), m_MaxHeight(maxHeight), m_Acceleration(1.f, gravity)
{
	m_Pos.x = posX;
	m_Pos.y = posY;
	m_Acceleration.x = 0.f;
	m_Acceleration.y = gravity;
	
	
	m_pCollide = new Collidable{ m_Ball, Collidable::Type::Player };


}

Ball::~Ball()
{
	delete m_pCollide;
	m_pCollide = nullptr;
}

void Ball::Draw()
{

	SetColor(Color4f(0.f, 0.f, 0.f, 1.f));
	FillPolygon(m_Vertices);
	for (int Index{}; Index < m_Vertices.size() - 1; ++Index)
	{
		SetColor(Color4f(1.f, 0.f, 0.f, 1.f));
		DrawLine(m_Vertices[Index], m_Vertices[Index + 1]);
	}
	DrawLine(m_Vertices[m_Vertices.size() - 1], m_Vertices[0]);


	FillEllipse(m_Pos.x, m_Pos.y, m_Ball.radius, m_Ball.radius);
	
	


}

void Ball::Update(float elapsedSec)
{
	/*m_Velocity.y = ((m_MaxHeight - (1/2) * m_Acceleration.y * (elapsedSec * elapsedSec)) / elapsedSec) * elapsedSec;*/
	m_Velocity.x += m_Acceleration.x * elapsedSec;
	m_Velocity.y += m_Acceleration.y * elapsedSec * 30.f;

	m_Pos.operator+=(m_Velocity * elapsedSec);
	m_Ball = Circlef(m_Pos.ToPoint2f(), m_Ball.radius);
	m_pCollide->SetHitBox(m_Ball);
	m_Time += elapsedSec;
	std::cout << m_Time << std::endl;
	HitInfo hitInfo{};
	SetRaycast(hitInfo);
	SetColor(Color4f(0.f, 0.f, 1.f, 1.f));
	DrawLine(m_RayStart, m_RayEnd, 2.f);
	SetColor(Color4f(0.f, 0.f, 1.f, 1.f));
	

	SetColor(Color4f(0.f, 1.f, 1.f, 1.f));
	DrawEllipse(hitInfo.intersectPoint, 10.f, 10.f);

	if (hitInfo.intersectPoint.y >= m_Pos.y)
	{
		m_Velocity.y = 0.f;
		m_Pos.y = hitInfo.intersectPoint.y;
		
	}

	if (m_Right == true)
	{
		if (m_Pos.y == hitInfo.intersectPoint.y)
		{
			m_Pos.x += 2.f;
			SetRaycast(hitInfo);
			m_Pos.y = hitInfo.intersectPoint.y;
		}
		else {
			m_Pos.x += 2.f;
		}
		
	}


	if (m_Left == true)
	{
		if (m_Pos.y == hitInfo.intersectPoint.y)
		{
			m_Pos.x -= 2.f;
			SetRaycast(hitInfo);
			m_Pos.y = hitInfo.intersectPoint.y;
		}
		else {
			m_Pos.x -= 2.f;
		}
	}




	if ( m_pCollide->GetCollision() == true)
	{
		std::cout << "habbababab" << std::endl;
	}

	/*std::cout << GetPos() << std::endl;*/
}

void Ball::SetVertices(std::vector<Point2f>& vertices)
{
	m_Vertices = vertices;
}

Vector2f Ball::GetPos()
{
	return m_Pos;
}


void Ball::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{

	switch ( e.keysym.sym )
	{
	case SDLK_LEFT:
		m_Left = true;
		break;
	case SDLK_RIGHT:
		m_Right = true;
		break;
	case SDLK_UP:
		m_Up = true;
		break;
	case SDLK_DOWN:
		m_Down = true;
		break;
	case SDLK_SPACE:
		m_Velocity.y = 500.f;
		break;
	}
}

void Ball::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	switch (e.keysym.sym)
	{
	case SDLK_LEFT:
		m_Left = false;
		break;
	case SDLK_RIGHT:
		m_Right = false;
		break;
	case SDLK_UP:
		m_Up = false;
		break;
	case SDLK_DOWN:
		m_Down = false;
		break;
	
	}
}

void Ball::SetRaycast(HitInfo& hitinfo)
{
	m_RayStart = Point2f(m_Pos.x, m_Pos.y + m_Ball.radius);
	m_RayEnd = Point2f(m_Pos.x, m_Pos.y - m_Ball.radius);
	Raycast(m_Vertices, m_RayStart, m_RayEnd, hitinfo);

}

Collidable* Ball::GetCollidable() const
{
	return m_pCollide;

}

