#pragma once
#include "Object.h"
class CIHolyWater : public CObject
{
public:
	CIHolyWater(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	void Draw2();
	~CIHolyWater();
};