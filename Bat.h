#pragma once
#include "Object.h"
class CBat : public CObject
{
	int y2;
public:
	CBat(int x, int y, int w, int h);
	virtual void Update(int t);
	virtual Box GetBox(GCamera *camera);
	~CBat();
};