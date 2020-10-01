#include "Bumeran.h"

CBumeran::CBumeran()
{
	TypeWeapon = 5;
	GTObject = new GTexture(BUMERAN_IMAGE_FILE, 3, 1, 3);
	GSObject = new GSprite(GTObject, BUMERAN_FRAME);
	Trend = 1;
}

CBumeran::~CBumeran()
{
}

void CBumeran::Update(GCamera *camera, int t)
{
	GSObject->Update(t);
	x += Vx;
	Vx -= 1 * Trend;
	//if ((Trend == 1 && Vx < 0) || (Trend == -1 && Vx > 0)) BumeranColide = 1;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	D3DXVECTOR2 pos1 = camera->Transform(sm_x, sm_y);
	if ((pos.x > pos1.x  && Trend == -1) || (pos.x < pos1.x && Trend == 1)) //Khi bumeran quay ngược lại thì xét tọa độ theo hướng simon để dừng không vẽ nữa
		IsFinish = 1;
}

void CBumeran::Create(float sm_x, float sm_y, int sm_trend)
{
	this->sm_x = sm_x;
	this->sm_y = sm_y;
	Weapon::Create(sm_x, sm_y + 10, sm_trend);
	Vx = BUMERAN_VX*Trend;
}
