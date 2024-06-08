#pragma once
class Balloon
{
public:
	Balloon(Point2f pos, Color4f color);

	void Draw();
	void GetRad(float rad);
	void ProgressBar();
	void GetHit(Rectf hitBox, bool hasItem);
	void reset();
	Rectf GetHitBox();
	Rectf GetReplenishHitBox();
	Rectf GetKnifeHitBox();




private:
	Point2f m_Pos;
	float m_Rad;
	Color4f m_Color;
	Rectf m_HitBox;
	Rectf m_ReplenishHitBox;
	Rectf m_KnifeHitBox;

};

