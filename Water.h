#ifndef _WATER_H_
#define _WATER_H_
#include"Object.h"

#define WATER_IMAGE_FILE "Resources/other/2.png"

class CWater : public CObject
{
	float x[3];
	float y[3];
	float Vx[3];
	float Vy[3];
	int FinishEffect;

public:
	CWater(float x, float y);
	virtual void Update(int t);
	virtual void Draw(GCamera *cam);
	~CWater();
};
#endif

