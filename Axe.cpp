#include "Axe.h"

CAxe::CAxe()
{
	TypeWeapon = 4;
	GTObject = new GTexture(AXE_IMAGE_FILE, 4, 1, 4);
	GSObject = new GSprite(GTObject, AXE_FRAME);
	Trend = 1;
}

CAxe::~CAxe()
{
}

void CAxe::Update(GCamera *camera, int t)
{
	GSObject->Update(t);
	x += Vx;
	y += Vy;
	Vy -= AXE_GRAVITY;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (pos.y > G_ScreenHeight + 20)
		IsFinish = 1;
}

void CAxe::Create(float sm_x, float sm_y, int sm_trend)
{
	Weapon::Create(sm_x, sm_y, sm_trend);
	Vx = AXE_VX*Trend;
	Vy = AXE_VY;
}
