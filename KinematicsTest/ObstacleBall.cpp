#include "ObstacleBall.h"
#include "pch.h"
#include "utils.h"
#include "Collidable.h"

using namespace utils;

ObstacleBall::ObstacleBall(float x, float y, float initialScale, float inflateSpeed)
    : m_Pos(x, y), m_InitialScale(initialScale), m_MaxScale(initialScale * 1.5f), m_InflateSpeed(inflateSpeed), m_Inflating(true), m_CurrentScale(initialScale) 
{
    m_pCollide = new Collidable{ Circlef(x, y, m_CurrentScale), Collidable::Type::Obstacle };
}

ObstacleBall::~ObstacleBall()
{
    /*delete m_pCollide;
    m_pCollide = nullptr;*/
}

void ObstacleBall::Update(float elapsedSec) {
    Inflate(elapsedSec);
    m_pCollide->SetHitBox(Circlef(m_Pos.x, m_Pos.y, m_CurrentScale));
}

void ObstacleBall::Draw() const {
    SetColor(Color4f(0.f, 1.f, 0.f, 1.f));
    FillEllipse(m_Pos.x, m_Pos.y, m_CurrentScale, m_CurrentScale);
}

void ObstacleBall::Inflate(float elapsedSec) {
    float scaleChange = m_InflateSpeed * elapsedSec;
    if (m_Inflating) {
        m_CurrentScale += scaleChange;
        if (m_CurrentScale >= m_MaxScale) {
            m_CurrentScale = m_MaxScale;
            m_Inflating = false;
        }
    }
    else {
        m_CurrentScale -= scaleChange;
        if (m_CurrentScale <= m_InitialScale) {
            m_CurrentScale = m_InitialScale;
            m_Inflating = true;
        }
    }
}

Vector2f ObstacleBall::GetPosition() const {
    return m_Pos;
}

Collidable* ObstacleBall::GetCollidable() const
{
    return m_pCollide;
}

float ObstacleBall::GetRadius() const {
    return m_CurrentScale;
}