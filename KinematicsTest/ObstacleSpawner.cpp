#include "pch.h"
#include "ObstacleSpawner.h"
#include "CollisionManager.h"
#include "utils.h"
using namespace utils;

ObstacleSpawner::ObstacleSpawner(float spawnBoxHeight, float spawnBoxWidth, float minDistanceBetweenBalls)
    : m_SpawnBoxHeight(spawnBoxHeight), m_SpawnBoxWidth(spawnBoxWidth), m_MinDistanceBetweenBalls(minDistanceBetweenBalls) {
    m_Scales = { 20.0f, 15.f, 45.f, 80.f }; 
    m_CollisionManager = new CollisionManager();
 
}

ObstacleSpawner::~ObstacleSpawner()
{
    delete m_CollisionManager;
    m_CollisionManager = nullptr;
}

void ObstacleSpawner::Update(float elapsedSec, const Vector2f& playerPos) {
  
    /*m_Obstacles.erase(
        std::remove_if(m_Obstacles.begin(), m_Obstacles.end(), [&](const ObstacleBall& obstacle) {
            return obstacle.GetPosition().y < playerPos.y - m_SpawnBoxHeight;
            }),
        m_Obstacles.end()
    );*/

    // Spawn new obstacles in the box above the player
    SpawnObstaclesInBox(playerPos);

    for (auto& obstacle : m_Obstacles) {
        obstacle.Update(elapsedSec);
    }
   
}

void ObstacleSpawner::Draw() {
    for (const auto& obstacle : m_Obstacles) {
        obstacle.Draw();
        
    }
}

void ObstacleSpawner::SetCollisionManager(CollisionManager* manager)
{
    m_CollisionManager = manager;
}

void ObstacleSpawner::SpawnObstaclesInBox(const Vector2f& playerPos) {
    float boxTopY = playerPos.y + m_SpawnBoxHeight;
    float boxBottomY = playerPos.y + 600.f;

    while (true) {
        float x = playerPos.x + (rand() % static_cast<int>(m_SpawnBoxWidth)) - (m_SpawnBoxWidth / 2);
        float y = boxBottomY + (rand() % static_cast<int>(m_SpawnBoxHeight));
        Vector2f spawnPosition(x, y);

        float initialScale = m_Scales[rand() % m_Scales.size()];
        if (!IsTooCloseToOtherObstacles(spawnPosition, initialScale)) {
            float inflateSpeed = 50.0f;
            m_Obstacles.emplace_back(spawnPosition.x, spawnPosition.y, initialScale, inflateSpeed);
            ObstacleBall obstacle(spawnPosition.x, spawnPosition.y, initialScale, inflateSpeed);
            m_CollisionManager->AddCollidable(obstacle.GetCollidable());

            if (obstacle.GetPosition().y <= -100)
            {
                m_CollisionManager->RemoveCollidable(obstacle.GetCollidable());
            }

        }
        else {
            break; // Stop spawning when no more valid positions are found
        }
    }


    
}

bool ObstacleSpawner::IsTooCloseToOtherObstacles(const Vector2f& position, float radius) const {
    for (const auto& obstacle : m_Obstacles) {
        float distance = GetDistance(obstacle.GetPosition().ToPoint2f(), position.ToPoint2f());
        if (distance < m_MinDistanceBetweenBalls + radius + obstacle.GetRadius()) {
            return true;
        }
    }
    return false;
}