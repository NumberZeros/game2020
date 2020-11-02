#include "CHolyWater.h"

CHolyWater::CHolyWater(D3DXVECTOR2 position)
{
	x = position.x;
	y = position.y;
}

CHolyWater::~CHolyWater()
{
}

void CHolyWater::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y - HOLY_WATER_ITEM_BBOX_HEIGHT;
	r = x + HOLY_WATER_ITEM_BBOX_WIDTH;
	b = y;
}

void CHolyWater::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CItem::Update(dt, coObjects);

	if (!isOnGround)
		vy += HOLY_WATER_ITEM_GRAVITY * dt;
}
