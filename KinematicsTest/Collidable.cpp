#include "pch.h"
#include "Collidable.h"
#include "utils.h"
#include <iostream>
using namespace utils;


Collidable::Collidable(Circlef hitBox, Type type):
	m_HitBox{hitBox},
	m_Type{type}
{
}

Circlef Collidable::GetBounds()
{
	return Circlef(m_HitBox);
}

Collidable::Type Collidable::GetObjType()
{
	return m_ObjType;
}

bool Collidable::GetCollision()
{
	return m_Collision;
}


void Collidable::SetHitBox(Circlef hitBox)
{
	m_HitBox = hitBox;
	
}

void Collidable::OnCollision(Collidable* other)
{
	

	if (IsOverlapping(m_HitBox, other->GetBounds()) == true)
	{
		m_ObjType = other->m_Type;
		m_Collision = true;
		std::cout << "DEAD" << std::endl;
	}
	else { m_Collision = false; }
}




