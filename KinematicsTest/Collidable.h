#pragma once
#include "utils.h"
using namespace utils;
class Collidable
{
public:
	enum class Type {
		Player, Obstacle
	};

	Collidable(Circlef hitBox, Type type);

	Circlef GetBounds();
	Type GetObjType();
	bool GetCollision();

	void SetHitBox(Circlef hitBox);
	void OnCollision(Collidable* other);


private:

	Circlef m_HitBox{};
	Type  m_Type{};

	Type  m_ObjType{};
	bool  m_Collision{ false };
};

