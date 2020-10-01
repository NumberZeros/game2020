#ifndef _MEDUSA_H_
#define _MEDUSA_H_
#include <d3dx9.h>
#include "Object.h"

#define MEDUSA_IMAGE_FILE "Resources/boss/1.png"
#define MEDUSA_STOP_IMAGE 4
#define MEDUSA_VX 0.06

class CBossMedusa : public CObject
{
	int TimeAtk;
	int IsCreateSnake;
	int WaitingTime;
	int Status;
	float sm_x;//Lấy vị trí của boss tại một thời điểm xác định
public:
	CBossMedusa(int x1, int y1, int w1, int h1);
	~CBossMedusa();
	virtual void Attack(Weapon *w = NULL);
	virtual void Go();
	virtual int CreateWeapon();
	virtual void GetSMPositionForBoss(float x);
	virtual void Update(GCamera *camera, int t);
	virtual Box GetBox(GCamera *camera);
	void Draw(GCamera * cam);
};
#endif
