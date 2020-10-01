#include "SnakeWeapon.h"

SnakeWeapon::SnakeWeapon()
{
	GTObject = new GTexture(IMAGE_FILE, 2, 1, 2);
	GSObject = new GSprite(GTObject, FRAME);
	Trend = -1;
	TypeWeapon = 2;
}

SnakeWeapon::~SnakeWeapon()
{
}

void SnakeWeapon::Update(GCamera *camera, int t)
{
	GSObject->Update(t);
	if (IsFalling)
	{
		y += Vy;
		Vy -= GRAVITY;
	}
	else
		x += Vx;

	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (pos.y > G_ScreenHeight - 20)
		IsFinish = 1;
}

void SnakeWeapon::Create(float sm_x, float sm_y, int sm_trend)
{
	Weapon::Create(sm_x - 64, sm_y + 16, sm_trend);
	Vx = VX*Trend;
	IsFalling = 1;
}
void SnakeWeapon::Draw(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	else GSObject->DrawFlipX(pos.x, pos.y);
}