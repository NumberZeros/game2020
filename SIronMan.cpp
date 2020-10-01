#include "SIronMan.h"

CSIronMan ::CSIronMan (int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/enemy/5.png", 4, 1, 4);
	GSObject = new GSprite(GTObject, 120);
	IsFalling = 1;
	Trend = -1;
	Vx = 0.18;
	health = 6;
}

CSIronMan ::~CSIronMan ()
{

}

Box CSIronMan ::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(this->x - this->w / 2, this->y + this->h / 2);
	return Box(pos.x, pos.y, this->w, this->h, Vx, -Vy);
}

void CSIronMan ::Update(int t)
{
	//Vx = Vx / 16;
	//Vy = Vy / 16;
	if (x > Max) Trend = -1;
	if (x < Min) Trend = 1;
		
	if (IsFalling == 1)
	{
		y += Vy;
		Vy = Vy - SIronMan_GRAVITY;
	}
	else
	{
		CObject::Update(t);
		Vx = 0.18 * Trend;
		x += Vx*t;	
	}
}

void CSIronMan ::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if (Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	if (Trend == 1) GSObject->DrawFlipX(pos.x, pos.y);
}

void CSIronMan ::Go() {
	if (IsJumping == 1 || IsFalling == 1) return;
	CObject::Go();
}

void CSIronMan ::StopFall(float y) {
	IsFalling = 0;
	this->Go();
	Vy = -1;
}

void CSIronMan::setMaxMin(int a, int b){
	Min = a + 16;
	Max = b - 20;
}

int CSIronMan::getMax(){
	return Max;
}
int CSIronMan::getMin(){
	return Min;
}