#pragma once
#include "Object.h"
class CIOrb : public CObject
{
public:
	CIOrb(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	virtual void StopFall(float y);
	~CIOrb();
};