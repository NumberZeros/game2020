#pragma once
#include "Object.h"
#define FISHMAN_JUMP 23
#define FISHMAN_STOP_IMAGE 2
#define FISHMAN_GRAVITY 1
#define FISHMAN_VX 0.18
class CFish : public CObject
{
private:
	float x1;
	int TimeAtk, waitingTime, IsCreateBullet;
public:
	CFish(int x, int y, int h, int w);
	virtual void Jump();
	virtual void Fall();
	virtual void Update(int t);
	virtual void StopFall(float y);
	virtual void Go();
	virtual void Draw(GCamera * cam);
	virtual void Attack(Weapon *w = NULL);
	virtual int CreateWeapon();
	~CFish();
};