#pragma once
#include "IAxe.h"
#include "IDagger.h"
#include "IHolyWater.h"
#include "IBoomerang.h"
#include "2Up.h"

class CBoardItem
{
private:
	int x1, y1;
	CIAxe *axe;
	CIDagger *dagger;
	CIHolyWater * hollywater;
	CIBoomerang *boomerang;
	C2Up *_2up;
	int whichItem;
public:
	void Draw();
	void		setwhichObj(int x1) { whichItem = x1; }
	CBoardItem();
	~CBoardItem();

};
