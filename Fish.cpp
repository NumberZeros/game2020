#include "Fish.h"

CFish::CFish(int x1, int y1, int h1, int w1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/enemy/3.png", 3, 1, 3);
	GSObject = new GSprite(GTObject, 120);
	Trend = -1;
	TimeAtk = -20;
	IsCreateBullet = 0;
}

CFish::~CFish()
{

}

void CFish::Jump()
{
	if (IsAttacking == 0 && IsJumping == 0 && IsFalling == 0)
	{
		if (IsJumping == 0)
		{
			Vy = FISHMAN_JUMP;
			GSObject->SelectIndex(FISHMAN_STOP_IMAGE);
			CObject::Jump();
		}
	}
}

void CFish::Fall()
{
	if (IsAttacking == 0 && IsJumping == 1 && IsFalling == 0)
	{
		if (IsFalling == 0)
		{
			Vy = -FISHMAN_JUMP;
			GSObject->SelectIndex(FISHMAN_STOP_IMAGE);
			CObject::Fall();
		}
	}
}
void CFish::Draw(GCamera * cam){
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if (Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	if (Trend == 1) GSObject->DrawFlipX(pos.x, pos.y);
}
void CFish::Update(int t){
	if (IsJumping == 1)
	{
		Vx *= IsGoing;
		y += Vy;
		x += Vx *t;
		Vy = Vy - FISHMAN_GRAVITY;
		GSObject->SelectIndex(FISHMAN_STOP_IMAGE);
		if (Vy <= 0)
		{
			this->Fall();
		}
	}
	else
	if (IsFalling == 1)
	{
		Vx *= IsGoing;
		x += Vx * t;
		y += Vy;
		Vy = Vy - FISHMAN_GRAVITY;
		GSObject->SelectIndex(FISHMAN_STOP_IMAGE);
	}
	else
	if (IsGoing == 1)
	{
		IsCreateBullet--;
		x += Vx * t;
		GSObject->Update(t);
		if (x < 3100)
			Trend = 1;
		if (GSObject->_index == 2){
			if (IsCreateBullet < TimeAtk)
			{
				TimeAtk = -50;
				this->Attack();
			}
		}
	}
	else GSObject->SelectIndex(FISHMAN_STOP_IMAGE);

}

void CFish::Go(){
	if (IsJumping == 1 || IsFalling == 1) return;
	this->Vx = FISHMAN_VX*Trend;
	CObject::Go();
}

void CFish::StopFall(float y){
	IsFalling = 0;
	this->y = y;
	this->Go();
	Vy = 0;
}

void CFish::Attack(Weapon *w)
{
	IsCreateBullet = 1;
	if (w)
	{
		//IsAttacking = 1;
		w->Create(x, y, Trend);
	}
}
int CFish::CreateWeapon()
{
	if (IsCreateBullet > 0)
	{
		IsCreateBullet = 0;
		return 1;
	}
	return 0;
}