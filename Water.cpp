#include "Water.h"

CWater::CWater(float x, float y)
{
	GTObject = new GTexture(WATER_IMAGE_FILE);
	GSObject = new GSprite(GTObject, 0);

	for (int i = 0; i < 3; i++)
	{
		this->x[i] = x;
		this->y[i] = y;
		this->Vx[i] = 0;
	}
	this->Vy[0] = 11;
	this->Vy[1] = 13;
	this->Vy[2] = 12;
}

CWater::~CWater()
{
}

void CWater::Update(int t)
{
	Vy[0] -= 0.9;
	Vy[1] -= 1.1;
	Vy[2] -= 0.8;

	if (Vy[0] > 0) Vx[0] = -5;
	else Vx[0] = 0;
	if (Vy[1] > 0) Vx[1] = 8;
	else Vx[1] = 0;

	x[0] += Vx[0];
	y[0] += Vy[0];
	x[1] += Vx[1];
	y[1] += Vy[1];
	x[2] += Vx[2];
	y[2] += Vy[2];

	//if (Vy[0] < -30) FinishEffect = 5;
}

void CWater::Draw(GCamera * cam)
{
	for (int i = 0; i < 3; i++)
	{
		D3DXVECTOR2 pos = cam->Transform(x[i], y[i]);
		GSObject->DrawFlipX(pos.x, pos.y);
	}
}
