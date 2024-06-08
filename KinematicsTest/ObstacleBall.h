#pragma once
#include "Collidable.h"
#include "Vector2f.h"
#include "utils.h"
#include <vector>

class ObstacleBall {
public:
    ObstacleBall(float x, float y, float initialScale, float inflateSpeed);
    ~ObstacleBall();

    void Update(float elapsedSec);
    void Draw() const;

    Vector2f GetPosition() const;
    Collidable* GetCollidable() const;
    float GetRadius() const;

private:
    Vector2f m_Pos;
    float m_InitialScale;
    float m_MinScale;
    float m_MaxScale;
    float m_CurrentScale;
    float m_InflateSpeed;
    bool m_Inflating;
    Collidable* m_pCollide{};

    void Inflate(float elapsedSec);
};