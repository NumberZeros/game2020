#include "Ghost.h"

Ghost::Ghost(D3DXVECTOR2 postition, int nx, int nextItemId)
{
	x = postition.x;
	y = postition.y;
	this->nx = nx;
	this->nextItemId = nextItemId;
	score = 200;
	vx = nx * GHOST_WALKING_SPEED;
	state = GHOST_STATE_WALKING;

	id = ID_GHOST;

	AddAnimation(ID_ANI_GHOST_WALK_RIGHT);
	AddAnimation(ID_ANI_GHOST_WALK_LEFT);
}

Ghost::~Ghost()
{
}
void Ghost::Update(DWORD dt, vector<LPGAMEOBJECT>* objects)
{
	CGameObject::Update(dt, objects);

	// fall down
	if (state != GHOST_STATE_ON_FIRE)
		vy += GHOST_GRAVITY * dt;
}

void Ghost::Render()
{
	int ani = 0;
	switch (state)
	{
	case GHOST_STATE_ACTIVE:
		if (nx > 0)
			ani = GHOST_ANI_WALK_RIGHT;
		else
			ani = GHOST_ANI_WALK_LEFT;
		break;
	case GHOST_STATE_ON_FIRE:
		ani = GHOST_ANI_ON_FIRE;
		break;
	default:
		break;
	}
	if (stopWatchStart > 0 && state != GHOST_STATE_ON_FIRE)
		animations[ani]->RenderFrame(x, y);
	else
		animations[ani]->Render(x, y);
}

void Ghost::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GHOST_STATE_ACTIVE)
	{
		left = x;
		top = y - GHOST_BBOX_HEIGHT;
		right = x + GHOST_BBOX_WIDTH;
		bottom = y;
	}
	else
		left = top = right = bottom = 0;
}