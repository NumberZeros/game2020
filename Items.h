#include "GCamera.h"
#include "ILHeart.h"
#include "ISHeart.h"
#include "IFood.h"
#include "IAxe.h"
#include "IDagger.h"
#include "IWhip.h"
#include "400Coin.h"
#include "600Coin.h"
#include "IHolyWater.h"
#include "IHolyCross.h"
#include "IFire.h"
#include "IBoomerang.h"
#include "2Up.h"
#include "IOrb.h"
#pragma once
class CItems
{
private:
	int whichItem;	 //Phân biệt items
	CLHeart *lheart;
	CSHeart *sheart;
	CFood *food;
	CIAxe *axe;
	CIDagger *dagger;
	CIWhip *whip;
	C400Coin *_400coin;
	C600Coin *_600coin;
	CIHolyWater * hollywater;
	CIHolyCross *cross;
	CIFire *fire;
	CIBoomerang *boomerang;
	C2Up *_2up;
	CIOrb *iorb;
	int timeDie = 0;
public:
	int			getwhichObj() { return whichItem; }
	void		setwhichObj(int x1) { whichItem = x1; }

	void Draw(GCamera * cam);
	Box GetBox(GCamera *camera);
	void Update(int t);
	void StopFall();
	void Fall();
	void setFireDie(int a);
	void setXFire(int a);
	void setYFire(int a);

	CItems(int io, int x1, int y1);

	int			getIsDie();
	void		setIsDie(bool a);
	void		setX(int a);
	void        setY(int a);
	void setCountTime();
	~CItems();

};
