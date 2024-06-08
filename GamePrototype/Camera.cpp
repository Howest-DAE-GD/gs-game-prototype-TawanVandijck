#include "pch.h"
#include "Camera.h"

Camera::Camera(float screenWidth, float screenHeight) :
	m_ScreenWidth{ screenWidth },
	m_ScreenHeight{ screenHeight },
    m_ZoomLevel{1.f},
    m_Center(Point2f(screenWidth / 2.0f, screenHeight / 2.0f))
{
}

void Camera::Aim(float levelW, float levelH, const Point2f& trackCenter)
{
    // Calculate the bottom-left position of the camera view to center trackCenter
    float camX = std::max(0.0f, trackCenter.x - m_ScreenWidth / 2);
    float camY = std::max(0.0f, trackCenter.y - m_ScreenHeight / 2);

    // Adjust camera to not go outside the level boundaries
    camX = std::min(camX, levelW - m_ScreenWidth);
    camY = std::min(camY, levelH - m_ScreenHeight);

    // Apply the calculated translation to the camera view
    /*glMatrixMode(GL_MODELVIEW);*/
    glPushMatrix();
    glTranslatef(-camX, -camY, 0.0f); // Negate to simulate camera movement

}

void Camera::Aim2(float levelW, float levelH, const Point2f& player1Pos, const Point2f& player2Pos)
{
    AdjustZoomAndPosition(player1Pos, player2Pos);

    // Apply transformations based on computed zoom and position
    glPushMatrix();
    glTranslatef(-m_Center.x + (m_ScreenWidth / 2) / m_ZoomLevel, -m_Center.y + (m_ScreenHeight / 2) / m_ZoomLevel, 0);
    glScalef(m_ZoomLevel, m_ZoomLevel, 1);
}

void Camera::Reset() 
{
    // Pop the last matrix to reset the transformations
   /* glMatrixMode(GL_MODELVIEW);*/
    glPopMatrix();
}

void Camera::AdjustZoomAndPosition(const Point2f& player1Pos, const Point2f& player2Pos)
{
    // Define buffer zone dimensions
    const float bufferZoneWidth = m_ScreenWidth * 0.95f;
    const float bufferZoneHeight = m_ScreenHeight * 0.95f;

    // Calculate bounding box of both players
    float minX = std::min(player1Pos.x, player2Pos.x);
    float maxX = std::max(player1Pos.x, player2Pos.x);
    float minY = std::min(player1Pos.y, player2Pos.y);
    float maxY = std::max(player1Pos.y, player2Pos.y);

    // Calculate needed view width and height to include both players
    float neededWidth = maxX - minX;
    float neededHeight = maxY - minY;

    // Adjust zoom based on the greater of the width or height ratio
    m_ZoomLevel = std::min(bufferZoneWidth / neededWidth, bufferZoneHeight / neededHeight);
    m_ZoomLevel = std::max(m_ZoomLevel, 1.0f);  // Ensure zoom does not exceed 1 (no zoom-in beyond original)

    // Set camera center between two players
    m_Center.x = (minX + maxX) / 2;
    m_Center.y = (minY + maxY) / 2;
}
