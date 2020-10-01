#pragma once
#include "Object.h"
class CMedusa : public CObject
{
	int y2;
public:
	CMedusa(int x, int y, int w, int h);
	virtual void Update(int x3, int t);
	virtual void Draw(GCamera * cam);
	virtual Box GetBox(GCamera *camera);
	~CMedusa();
};