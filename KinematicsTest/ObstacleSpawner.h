#pragma once
#include "CollisionManager.h"
#include "ObstacleBall.h"
#include <vector>

class ObstacleSpawner {
public:
    ObstacleSpawner(float spawnBoxHeight, float spawnBoxWidth, float minDistanceBetweenBalls);
    ~ObstacleSpawner();

    void Update(float elapsedSec, const Vector2f& playerPos);
    void Draw();
    void SetCollisionManager(CollisionManager* manager);

private:
    float m_SpawnBoxHeight;
    float m_SpawnBoxWidth;
    float m_MinDistanceBetweenBalls;
    std::vector<float> m_Scales;
    CollisionManager* m_CollisionManager;


    std::vector<ObstacleBall> m_Obstacles;

    void SpawnObstaclesInBox(const Vector2f& playerPos);
    bool IsTooCloseToOtherObstacles(const Vector2f& position, float radius) const;
};