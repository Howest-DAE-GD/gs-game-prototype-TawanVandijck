#pragma once
#include "Collidable.h"
#include <vector>

class CollisionManager
{
public:
    void AddCollidable(Collidable* obj);
    void RemoveCollidable(Collidable* obj);
    void CheckCollision();


private:
	std::vector<Collidable*> collidables;
};

