#ifndef _BONETOWER_H_
#define _BONETOWER_H_

#include "Object.h"

#define BONETOWER_IMAGE_FILE "Resources/Enemy/8.png"
class CDragonHead :public CObject
{
public:
	int timeAtk = 0;
	int IsCreateBullet;
	int RedStatus = 0;
	int health;
	CDragonHead(int x1, int y1, int h1, int w1);
	~CDragonHead();
	virtual void Attack(Weapon *w = NULL);
	virtual void Update(int t);
	virtual void Draw(GCamera * cam);
	virtual int CreateWeapon();
};
#endif