#pragma once
#include "Object.h"
class CSoldier : public CObject
{
public:
	CSoldier(int x, int y, int h, int w);
	virtual Box GetBox(GCamera *camera);
	~CSoldier();
};