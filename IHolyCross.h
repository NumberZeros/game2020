#pragma once
#include "Object.h"
class CIHolyCross : public CObject
{
public:
	CIHolyCross(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	void Draw2();
	~CIHolyCross();
};