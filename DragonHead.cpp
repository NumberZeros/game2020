#include "DragonHead.h"

CDragonHead::CDragonHead(int x1, int y1, int h1, int w1)
{
	Vx = 0;
	Vy = 0;
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture(BONETOWER_IMAGE_FILE, 1, 1, 1);
	GSObject = new GSprite(GTObject, 100);
	Trend = -1;
	this->x = x;
	this->y = y;
	IsCreateBullet = 0;
	timeAtk = 0;
	health = 10;
}

CDragonHead::~CDragonHead()
{
}

void CDragonHead::Update(int t)
{
	if (IsGoing)
	{
		if (timeAtk >= 0)
		{
			timeAtk++;
			if (timeAtk > 5 && timeAtk < 25) RedStatus = 1; else RedStatus = 0;
			if (timeAtk % 30 == 0) IsCreateBullet = 1;
			if (timeAtk >= 90) timeAtk = -1;
		}
		else
		if (timeAtk < 0)
		{
			timeAtk--;
			if (timeAtk == -5) Trend = -Trend;
			if (timeAtk == -15) Trend = -Trend;
			if (timeAtk == -100) timeAtk = 0;
		}
	}
}

void CDragonHead::Attack(Weapon *w)
{
	if (w)
	{
		IsAttacking = 1;
		w->Create(x, y, Trend);
	}
}

int CDragonHead::CreateWeapon()
{
	if (IsCreateBullet > 0)
	{
		IsCreateBullet = 0;
		return 1;
	}
	return 0;
}

void CDragonHead::Draw(GCamera * camera)
{
	/*if (IsHurting) IsHurting--;
	else EndHurt = 1;*/

	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (RedStatus) GSObject->SetARGB(255, 0, 0, 0);
	else  GSObject->SetARGB();
	if (Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	else GSObject->DrawFlipX(pos.x, pos.y);
}
