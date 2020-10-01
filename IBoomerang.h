#pragma once
#include "Object.h"
class CIBoomerang : public CObject
{
public:
	CIBoomerang(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	void Draw2();
	~CIBoomerang();
};