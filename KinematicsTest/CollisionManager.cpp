#include "pch.h"
#include "CollisionManager.h"
#include "Collidable.h"
#include "iostream"
#include "utils.h"
#include <iostream>
using namespace utils;

void CollisionManager::AddCollidable(Collidable* obj)
{
	if (obj == nullptr)
	{
		std::cout << "nope";
	}
	else
	{
		collidables.push_back(obj);
		/*if (obj->GetObjType() == Collidable::Type::Player)
		{
			std::cout << "haba";
		}*/
	}
}

void CollisionManager::RemoveCollidable(Collidable* obj)
{
	collidables.erase(std::remove(collidables.begin(), collidables.end(), obj), collidables.end());
}

void CollisionManager::CheckCollision()
{
	
	for (int index1{}; index1 < collidables.size(); ++index1)
	{
		for (int index2 = index1 + 1; index2 < collidables.size(); ++index2)
		{
			
			collidables[index1]->OnCollision(collidables[index2]);
				
			
		}
	}
}
