#include "CBatBoss.h"

CBatBoss::CBatBoss(int x1, int y1, int h1, int w1) {
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	Vx = 3;
	Vy = 3;
	GTObject = new GTexture(BOSSBAT_IMAGE_FILE, 3, 1, 3);
	GSObject = new GSprite(GTObject, BOSSBAT_FRAME_NRM);
	Status = 0;
	WaitingTime = 0;
	Dy = y;
	srand(time(NULL));
	WT = rand() % (1500 - 1000 + 1) + 1000;
	bat_x[0] = 5200; bat_x[1] = 5250; bat_x[2] = 5544;
	bat_y[0] = 250 + 416; bat_y[1] = 270 + 416; bat_y[2] = 300 + 416;
}

void CBatBoss::Draw(GCamera * cam)
{
	if (IsHurting)
	{
		IsHurting--;
	}
	else EndHurt = 1;
	D3DXVECTOR2 pos = cam->Transform(x, y);
	GSObject->DrawFromCenter(pos.x, pos.y);
	//else GSObject->DrawFlipX(pos.x, pos.y);
}
void CBatBoss::Update(GCamera *cam,int t){
	if (Status == 0) //Trạng thái ngủ
	{
		GSObject->SelectIndex(BOSSBAT_STOP_IMAGE);
		return;
	}
	// Update tile chuyển động
	GSObject->Update(t);
	if (GSObject->_index == 0) GSObject->SelectIndex(1);

	// Xử lí chuyển động 
	if (Status == 1)
	{
		GSObject->_timeAni = BOSSBAT_FRAME_NRM;
		WaitingTime += t;
		if (WaitingTime > WT)
		{
			WaitingTime = 0;
			Status = 2;
		}
	}
	else
		if (Status == 2)
		{
			GSObject->_timeAni = BOSSBAT_FRAME_ATK;
			x1 = x - sm_x;
			if (x1 == 0) x1 = 1;
			y1 = y - sm_y;
			Vx = -x1/55;// nham biet duoc di chuyen qua trai hay phai(tốc độ bay xuống)
			a = y1 / (x1*x1);// vi muon phu thuoc vao x va y, quy dao doi bay da dang hon
			Status = 3;
			y_before = y;// luu lại vị trí tiếp theo cho nó là vị trí ban đầu
		}
		else
			if (Status == 3)
			{
				x += Vx;
				y = (x - sm_x)*(x - sm_x)*a + sm_y;//y giam theo x, x theo khuyn huong gan x_sm, sm_y + số dương nhỏ dần
				if (y >= y_before || x + GTObject->FrameWidth / 2 >= cam->viewport.x + G_ScreenWidth || x - GTObject->FrameWidth / 2 <= cam->viewport.x)
				{
					Status = 4;
					GSObject->_timeAni = BOSSBAT_FRAME_NRM;
				}
				y_before = y;
			}
			else
				if (Status == 4)
				{
					WaitingTime += t;
					if (WaitingTime > 50)
					{
						WaitingTime = 0;
						Status = 5;
					}
				}
				else
					if (Status == 5)
					{
						GSObject->_timeAni = BOSSBAT_FRAME_ATK;
						x2 = FindX();
						y2 = FindY();
						x1 = x - x2;
						y1 = y - y2;
						Vx = -x1 / 70;// toc do bay len cua doi
						a = y1 / x1;
						Status = 6;
					}
					else
						if (Status == 6)
						{
 						 	x += Vx;
							y = (x - x2)*a + y2;// y2 + số âm nhỏ dần
							if (y >= y2 )
							{
								Status = 1;
								GSObject->_timeAni = BOSSBAT_FRAME_NRM;
								srand(time(NULL));
								WT = rand() % (1500 - 1000 + 1) + 1000;
							}
						}

}

void CBatBoss::GetSMPositionForBoss(float x, float y, int Trend)
{
	if (Status >= 2) return;
	sm_x = x;
	sm_y = y;
	sm_Trend = Trend;
}
float CBatBoss::FindX()
{
	//Tìm tọa độ x để bay về
	srand(time(NULL));
	int RandomX = rand() % 3;
	return bat_x[RandomX];
}

float CBatBoss::FindY()
{
	srand(time(NULL));
	int RandomY = rand() % 3;
	return bat_y[RandomY];
}

float CBatBoss::FindX(GCamera *camera)
{
	//Tìm tọa độ x để bay về
	srand(time(NULL));
	int RandomX = rand() % 3;
	if (RandomX == 0) return camera->viewport.x + G_ScreenWidth / 10;
	if (RandomX == 1) return camera->viewport.x + G_ScreenWidth / 2;
	if (RandomX == 2) return camera->viewport.x + 8 * G_ScreenWidth / 10;
}

float CBatBoss::FindY(GCamera *camera)
{
	srand(time(NULL));
	int RandomY = rand() % 3;
	if (RandomY == 0) return camera->viewport.y - G_ScreenHeight / 2;
	if (RandomY == 1) return camera->viewport.y - 3 * G_ScreenHeight / 5;
	if (RandomY == 2) return Dy;
}
Box CBatBoss::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2, y + GTObject->FrameHeight / 2);
	return Box(pos.x, pos.y, GTObject->FrameWidth, GTObject->FrameHeight, Vx, -Vy);
}

void CBatBoss::Go() {
	CObject::Go();
	Status = 1;
	GSObject->_timeAni = 50;

	//GSObject->SelectIndex(1);
}