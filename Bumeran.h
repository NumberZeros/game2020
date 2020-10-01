#ifndef _BUMERAN_H_
#define _BUMERAN_H_
#include "Weapon.h"

#define BUMERAN_IMAGE_FILE "Resources/weapon/4.png"
#define BUMERAN_FRAME 7
#define BUMERAN_VX 20

class CBumeran : public Weapon
{
public:
	CBumeran();
	~CBumeran();
	float sm_x, sm_y;
	virtual void Update(GCamera *camera, int t);
	virtual void Create(float sm_x, float sm_y, int sm_trend);
};
#endif

