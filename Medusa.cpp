#include "Medusa.h"

CMedusa::CMedusa(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	y2 = y1;
	Vx = 0.31;
	GTObject = new GTexture("./Resources/enemy/6.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 40);
	Trend = 1;
}
void CMedusa::Update(int x3, int t)
{
	//if ((x  > x3 && Trend == 1) || (x<x3 && Trend ==-1))
	{
		x += Vx*Trend*t;
		Vy = sin(x*0.03) * 55.5;//Nếu dễ chết thì chỉnh về 20
		//sin(_pos_x*0.03)*95.5 + _pos_old_y;
		y = y2 + Vy;
		if (GSObject->GetIndex() < 2)
			GSObject->Update(t);
		else
			GSObject->_index = 0; //Vy = -Vy;
	}
	if (x>1600 && y >= 862) Trend = -1;
}

void CMedusa::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if (Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	if (Trend == 1) GSObject->DrawFlipX(pos.x, pos.y);
}
CMedusa::~CMedusa()
{

}
Box CMedusa::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(this->x - this->w / 2, this->y + this->h / 2);
	return Box(pos.x, pos.y, this->w, this->h, Vx, -Vy);
}
