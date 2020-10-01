#include "BoardItem.h"

CBoardItem::CBoardItem()
{
	x1 = 330;
	y1 = 40;
	whichItem = 0;
	axe = new CIAxe(x1, y1, 30, 28);
	boomerang = new CIBoomerang(x1, y1, 24, 20);
	dagger = new CIDagger(x1, y1, 32, 18);
	hollywater = new CIHolyWater(x1, y1, 32, 18);
}


CBoardItem::~CBoardItem()
{

}


void CBoardItem::Draw()
{

	switch (whichItem)
	{
	case 3:
	{
		axe->Draw2();
	}break;
	case 6:
	{
		boomerang->Draw2();
	}break;
	case 10:
	{
		dagger->Draw2();
	}break;
	case 13:
	{
		hollywater->Draw2();
	}break;
	default:
	{

	}break;

	}
}

