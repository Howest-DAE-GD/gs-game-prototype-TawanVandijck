#include "pch.h"
#include "Balloon.h"
#include "iostream"
#include "utils.h"
using namespace utils;

Balloon::Balloon(Point2f pos, Color4f color):
	m_Pos{pos},
	m_Color{color}
{
	m_Rad = 10.f;
	m_HitBox = Rectf(m_Pos.x - 5.f, m_Pos.y - 50.f, 10.f, 10.f);
	m_ReplenishHitBox = Rectf(350.f, 10.f, 20.f, 20.f);
	m_KnifeHitBox = Rectf(400.f, 10.f, 20.f, 20.f);
}

void Balloon::Draw()
{
	SetColor(m_Color);
	FillEllipse(m_Pos, m_Rad, m_Rad);
	SetColor(Color4f(1.f, 0.f, 1.f, 1.f));
	DrawRect(m_ReplenishHitBox);
	SetColor(Color4f(0.5f, 1.f, 1.f, 1.f));
	DrawRect(m_KnifeHitBox);

	SetColor(Color4f(1.f, 0.f, 0.f, 1.f));
	DrawRect(m_HitBox);
}

void Balloon::GetRad(float rad)
{
	m_Rad += rad;

	if (m_Rad > 40.f) { m_Rad = 40.f; }
	
}

void Balloon::ProgressBar()
{
	
}

void Balloon::GetHit(Rectf hitBox, bool hasItem)
{
	

	if (IsOverlapping(m_HitBox, hitBox) == true && hasItem == true)
	{
		m_Rad += 5.f;

		if (m_Rad > 40.f) { m_Rad = 40.f; }
		
		std::cout << "Hit" << std::endl;
	}
}

void Balloon::reset()
{
	m_Rad = 10.f;
}

Rectf Balloon::GetHitBox()
{
	return m_HitBox;
}

Rectf Balloon::GetReplenishHitBox()
{
	return m_ReplenishHitBox;
}

Rectf Balloon::GetKnifeHitBox()
{
	return m_KnifeHitBox;
}




