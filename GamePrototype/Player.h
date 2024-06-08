#pragma once
class Player
{
public:
	Player(Point2f pos, float width, float height, Color4f color);

	void Draw();
	void Update(float elapsedSec);
	void Movement(int direction);
	Point2f GetPos();
	Rectf GetHitBox();
	Circlef GetWeaponHitBox();
	void HasItem(bool item);
	bool CheckItem();
	void IsOverlap(Rectf hitBox);
	void ReplenishOverlap(Rectf hitBox);
	void WeaponOverlap(Rectf hitBox);
	void PlayerWeaponOverlap(Circlef hitBox);
	


private:
	Point2f m_Pos;
	float   m_Width;
	float   m_Height;
	Color4f m_Color;
	bool    m_Move[4];

	Rectf m_HitBox; 
	bool m_HasItem{ false };
	bool m_HasWeapon{ false };
	Circlef m_WeaponHitBox;
};

