#ifndef _AXE_H_
#define _AXE_H_
#include "Weapon.h"

#define AXE_IMAGE_FILE "Resources/weapon/3.png"
#define AXE_VX 8
#define AXE_VY 17
#define AXE_GRAVITY 1
#define AXE_FRAME 50

class CAxe : public Weapon
{
public:
	CAxe();
	~CAxe();

	virtual void Update(GCamera *camera, int t);
	virtual void Create(float sm_x, float sm_y, int sm_trend);
};
#endif
