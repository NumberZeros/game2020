#include "BossMedusa.h"

CBossMedusa::CBossMedusa(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	Vx = 0;
	Vy = 0;
	GTObject = new GTexture(MEDUSA_IMAGE_FILE, 5, 1, 5);
	GSObject = new GSprite(GTObject, 100);
	Trend = 1;
	IsGoing = 0;
	WaitingTime = 0;
	IsCreateSnake = 0;
	TimeAtk = -200;
	Status = 0;
}
void CBossMedusa::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if (IsHurting)
	{
		IsHurting--;
	}
	else EndHurt = 1;
	if (Trend == -1)GSObject->DrawFromCenter(pos.x, pos.y);
	else GSObject->DrawFlipX(pos.x, pos.y);
}
void CBossMedusa::Update(GCamera * camera, int t)
{
	isBoss = false;
	IsCreateSnake--;
	if (Status == 0) //Trạng thái ngủ
	{
		GSObject->SelectIndex(MEDUSA_STOP_IMAGE);
		isBoss = true;
		return;
	}
	GSObject->Update(t);
	if (GSObject->_index == 4) GSObject->SelectIndex(0);

	if (IsGoing == 1 && WaitingTime == 0)
	{
		x += MEDUSA_VX*Trend * t + Trend;
		y = sin(x / 15) * 15 + 150 + AutoFit;
		if (IsCreateSnake < TimeAtk)
		{
			TimeAtk = -120;
			this->Attack();
		}
	}
	//Đổi hướng của bossmedusa
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if ((pos.x <= GTObject->FrameWidth / 2) || (x < sm_x && sm_x - x > G_ScreenWidth / 2))
		Trend = 1;
	if ((pos.x >= G_ScreenWidth - GTObject->FrameWidth / 2 - 64) || (sm_x < x && x - sm_x> G_ScreenWidth / 2))
		Trend = -1;

	if (WaitingTime) WaitingTime--;
	if (IsHurting == 25)
		WaitingTime = 20;
}
void CBossMedusa::Attack(Weapon *w)
{
	IsCreateSnake = 1;
	WaitingTime = 20;
	if (w)
	{
		IsAttacking = 1;
		if (sm_x < x)
			w->Create(x, y - 80, -1);
		else w->Create(x, y - 80, 1);
	}
}

void CBossMedusa::Go()
{
	CObject::Go();
	Status = 1;
	GSObject->SelectIndex(0);
	Vx = MEDUSA_VX*Trend;
}
void CBossMedusa::GetSMPositionForBoss(float x)
{
	sm_x = x;
}
int CBossMedusa::CreateWeapon()
{
	if (IsCreateSnake > 0)
	{
		IsCreateSnake = 0;
		return 1;
	}
	return 0;
}

Box CBossMedusa::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2, y + GTObject->FrameHeight / 2);
	return Box(pos.x, pos.y, GTObject->FrameWidth, GTObject->FrameHeight, Vx, -Vy);
}
