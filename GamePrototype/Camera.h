#pragma once
class Camera
{
public:
	Camera(float screenWidth, float screenHeight);

	void Aim(float levelW, float levelH, const Point2f& trackCenter);
	void Aim2(float levelW, float levelH, const Point2f& player1Pos, const Point2f& player2Pos);
	void Reset();


private:
	float m_ScreenWidth;
	float m_ScreenHeight;
	float m_ZoomLevel;
	Point2f m_Center;

	void AdjustZoomAndPosition(const Point2f& player1Pos, const Point2f& player2Pos);

};

