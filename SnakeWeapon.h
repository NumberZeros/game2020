#ifndef _SnakeWeapon_H_
#define _SnakeWeapon_H_
#include "Weapon.h"

#define IMAGE_FILE "Resources/boss/2.png"
#define VX 5
#define VY 11
#define GRAVITY 1
#define FRAME 80

class SnakeWeapon : public Weapon
{
public:
	SnakeWeapon();
	~SnakeWeapon();
	virtual void Update(GCamera *camera, int t);
	virtual void Draw(GCamera *camera);
	virtual void Create(float fm_x, float fm_y, int fm_trend);
};
#endif