#include "Soldier.h"

CSoldier::CSoldier(int x1, int y1, int h1, int w1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/enemy/5.png", 4, 1, 4);
	GSObject = new GSprite(GTObject, 120);
}

CSoldier::~CSoldier()
{

}

Box CSoldier::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2 - 18, y + h / 2 - 16);
	return Box(pos.x, pos.y, w - 32, h, 0, 0);
}
