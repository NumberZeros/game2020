#include "CGhost.h"

//CGhost::CGhost(D3DXVECTOR2 postition, int nx)
//{
//	x = postition.x;
//	y = postition.y;
//	this->nx = nx;
//	vx = nx * GHOST_WALKING_SPEED;
//	state = GHOST_STATE_ACTIVE;
//
//
//	AddAnimation(GHOST_ANI_WALKING_RIGHT);
//	AddAnimation(GHOST_ANI_WALKING_LEFT);
//}
//
//CGhost::~CGhost()
//{
//
//}
void CGhost::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (state == GHOST_STATE_ACTIVE)
	{
		left = x;
		top = y;
		right = x + GHOST_BBOX_WIDTH;
		bottom = y - GHOST_BBOX_HEIGHT;
	}
	else
		left = top = right = bottom = 0;
}

void CGhost::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Ghost can interact with the world and to each of them too!
	// 
	if (state != GHOST_STATE_ON_FIRE)
		vy += GHOST_GRAVITY * dt;
}

void CGhost::Render()
{
	int ani = 0;
	switch (state)
	{
	case GHOST_STATE_ACTIVE:
			if (nx > 0)
				ani = GHOST_ANI_WALKING_RIGHT;
			else
				ani = GHOST_ANI_WALKING_LEFT;
			break;
	}
	//RenderBoundingBox();
	animations[ani]->Render(x, y);
}

void CGhost::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GHOST_STATE_DIE:
		y += GHOST_BBOX_HEIGHT + 1;
		vx = 0;
		vy = 0;
		break;
	case GHOST_STATE_WALKING_LEFT:
		vx = -GHOST_WALKING_SPEED;
		break;
	case GHOST_STATE_WALKING_RIGHT:
		vx = GHOST_WALKING_SPEED;
		nx = 1;
		break;
	}
}
