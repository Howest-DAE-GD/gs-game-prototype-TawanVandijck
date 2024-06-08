#include "pch.h"
#include "Camera.h"

Camera::Camera(float screenWidth, float screenHeight) :
	m_ScreenWidth{ screenWidth },
	m_ScreenHeight{ screenHeight }
{
}

void Camera::Aim(float levelW, float levelH, const Point2f& trackCenter)
{
    float camX = std::max(0.0f, trackCenter.x - m_ScreenWidth / 2);
    float camY = std::max(0.0f, trackCenter.y - m_ScreenHeight / 2);

    camX = std::min(camX, levelW - m_ScreenWidth);
    camY = std::min(camY, levelH - m_ScreenHeight);

    glPushMatrix();
    glTranslatef(-camX, -camY, 0.0f); 

}


void Camera::Reset() 
{
    glPopMatrix();
}


