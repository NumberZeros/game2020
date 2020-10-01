#pragma once
#include "Object.h"
class CIAxe: public CObject
{
public:
	CIAxe(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	void Draw2();
	void Update(int t);
	CIAxe();
	~CIAxe();
};

