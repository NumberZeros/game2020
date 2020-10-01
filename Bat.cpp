#include "Bat.h"

CBat::CBat(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	y2 = y1;
	Vx = -0.31;
	GTObject = new GTexture("./Resources/enemy/0.png", 4, 1, 4);
	GSObject = new GSprite(GTObject, 40);
}
void CBat::Update(int t)
{
	/*if (x + w > G_ScreenWidth )
	{
	Vx = -Vx;
	}*/
	x += Vx*t;
	Vy = sin(x*0.03)*41.3;//sin(x*0.03)*4.13;
	y = y2 + Vy;
	if (GSObject->GetIndex() < 2)
		GSObject->Update(t);
	else
		GSObject->_index = 1; //Vy = -Vy;
}

CBat::~CBat()
{

}
Box CBat::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w - 32, h, Vx, -Vy);

}
