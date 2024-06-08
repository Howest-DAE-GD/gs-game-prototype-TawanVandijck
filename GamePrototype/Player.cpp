#include "pch.h"
#include "Player.h"
#include "utils.h"
using namespace utils;

Player::Player(Point2f pos, float width, float height, Color4f color):
	m_Pos{pos},
	m_Width{width},
	m_Height{height},
	m_Color{color}
{
	for (int index{}; index <= 3; ++index)
	{
		m_Move[index] = false;
	}

	m_HitBox = Rectf(m_Pos.x, m_Pos.y, m_Width, m_Height);
	m_WeaponHitBox = Circlef(m_Pos, 20.f);
}

void Player::Draw()
{

	if (m_HasWeapon == true)
	{
		SetColor(Color4f(0.5f, 1.f, 1.f, 1.f));
		FillEllipse(m_Pos.x + 10.f, m_Pos.y + 10.f, m_WeaponHitBox.radius, m_WeaponHitBox.radius);
	}

	SetColor(m_Color);
	FillRect(m_Pos, m_Width, m_Height);

	if (m_HasItem == true)
	{
		SetColor(Color4f(1.f, 0.f, 1.f, 1.f));
		FillRect(m_Pos.x + 17.f, m_Pos.y + 5.f, 8.f, 12.f);
	}

	

}

void Player::Update(float elapsedSec)
{
	if (m_Move[0] == true) { m_Pos.x -= 1.5f; }
	if (m_Move[1] == true) { m_Pos.x += 1.5f; }
	if (m_Move[2] == true) { m_Pos.y += 1.5f; }
	if (m_Move[3] == true) { m_Pos.y -= 1.5f; }

	m_HitBox = Rectf(m_Pos.x, m_Pos.y, m_Width, m_Height);
}

void Player::Movement(int direction)
{
	if (direction == 0) { m_Move[0] = true; }
	else if (direction == 4) { m_Move[0] = false; }

	if (direction == 1) { m_Move[1] = true; }
	else if (direction == 5) { m_Move[1] = false; }

	if (direction == 2) { m_Move[2] = true; }
	else if (direction == 6) { m_Move[2] = false; }

	if (direction == 3) { m_Move[3] = true; }
	else if (direction == 7) { m_Move[3] = false; }
}

Point2f Player::GetPos()
{
	return m_Pos;
}

Rectf Player::GetHitBox()
{
	return m_HitBox;
}

Circlef Player::GetWeaponHitBox()
{
	return m_WeaponHitBox;
}

void Player::HasItem(bool item)
{
	m_HasItem = item;
}

bool Player::CheckItem()
{
	return m_HasItem;
}

void Player::IsOverlap(Rectf hitBox)
{
	if (IsOverlapping(m_HitBox, hitBox))
	{
		m_HasItem = false;
	}
}

void Player::ReplenishOverlap(Rectf hitBox)
{
	if (IsOverlapping(m_HitBox, hitBox) == true && m_HasWeapon == false)
	{
		m_HasItem = true;
	}
}

void Player::WeaponOverlap(Rectf hitBox)
{
	if (IsOverlapping(m_HitBox, hitBox) == true && m_HasItem == false)
	{
		m_HasWeapon = true;
	}
}

void Player::PlayerWeaponOverlap(Circlef hitBox)
{
	if (IsOverlapping(m_HitBox, hitBox))
	{
		m_HasItem = false;
	}
}



