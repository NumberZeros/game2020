#include "IHolyWater.h"

CIHolyWater::CIHolyWater(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/item/9.png");
	GSObject = new GSprite(GTObject);
	Vy = 0.06;
}

CIHolyWater::~CIHolyWater()
{

}
Box CIHolyWater::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void CIHolyWater::Update(int t)
{
	if (IsFalling == 1)
	{
		Vy = Vy - 0.012;
		y += Vy*t;
	}
}
void CIHolyWater::Draw2()
{
	GSObject->DrawFromTL(x, y);
}