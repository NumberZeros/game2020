#pragma once
#include "GameObject.h"

#define GHOST_WALKING_SPEED 0.027f;
#define GHOST_GRAVITY	0.0006f
#define GHOST_STATE_ON_FIRE 0
#define GHOST_ANI_ON_FIRE 0
#define ID_GHOST 04

#define GHOST_STATE_ACTIVE	5
#define GHOST_STATE_WALKING 100
#define GHOST_STATE_DIE 200

#define GHOST_BBOX_WIDTH		15
#define GHOST_BBOX_HEIGHT		30

#define GHOST_ANI_DIE 3

#define GHOST_ANI_WALK_RIGHT	1
#define GHOST_ANI_WALK_LEFT		2
#define ID_ANI_GHOST_WALK_RIGHT 05
#define ID_ANI_GHOST_WALK_LEFT 06

class Ghost : 
	public CGameObject 
{
	Ghost(D3DXVECTOR2 postition, int nx, int nextItemId);
	~Ghost();
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
};

