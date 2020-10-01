#include "IOrb.h"

CIOrb::CIOrb(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/item/13.png",2,1,2);
	GSObject = new GSprite(GTObject);
	Vy = 18;
}

CIOrb::~CIOrb()
{

}
Box CIOrb::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void CIOrb::Update(int t)
{
	if (IsFalling == 1)
	{
		Vy = Vy - 0.5;
		if (Vy <= 0) {
			Vy = 0;
		}
		y -= Vy;
		//y = y -3;
	}
	GSObject->Update(t);
}
void CIOrb::StopFall(float y)
{
	this->y += y;
	CObject::StopFall(y);
}