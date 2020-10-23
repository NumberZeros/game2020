#pragma once
#include "GameObject.h"

#define SIMON_WALKING_SPEED		0.1f 
//0.1f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_JUMP_DEFLECT_SPEED 0.2f
#define SIMON_GRAVITY			0.002f
#define SIMON_DIE_DEFLECT_SPEED	 0.5f

#define SIMON_ATTACK_TIME 600

#define SIMON_STATE_IDLE			0
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_DIE				400
#define SIMON_STATE_SIT_DOWN		500
#define STATE_ATTACK				600
#define STATE_ATTACK_RIGHT			601
#define STATE_ATTACK_LEFT			602


#define SIMON_ANI_BIG_IDLE_RIGHT		0
#define SIMON_ANI_BIG_IDLE_LEFT			1

#define SIMON_ANI_BIG_WALKING_RIGHT			2
#define SIMON_ANI_BIG_WALKING_LEFT			3

#define SIMON_ANI_SIT_DOWN_RIGHT			4
#define SIMON_ANI_SIT_DOWN_LEFT				5

#define SIMON_ANI_ATTACK_RIGHT				6
#define SIMON_ANI_ATTACK_LEFT				7

#define SIMON_ANI_ATTACK_SIT_RIGHT				8
#define SIMON_ANI_ATTACK_SIT_LEFT				9

#define SIMON_HEGHT				30
#define SIMON_WIDTH				24

#define SIMON_HEGHT_IS_SIT				23
#define SIMON_HEGHT_RESET_SIT			7

#define SIMON_WIDTH_RESET_ATTACK		7

#define SIMON_ANI_DIE				8

#define	SIMON_LEVEL_SMALL	1
#define	SIMON_LEVEL_BIG		2

#define SIMON_UNTOUCHABLE_TIME 5000


class CSimon : public CGameObject
{
	int level;
	int untouchable;
	int height = 30;
	int width = 17;
	bool isSit;
	bool isAttack;
	int actionAttack = 0;	// 0 right 1 left
	
	DWORD untouchable_start;
	DWORD action_time;
public: 
	CSimon() : CGameObject()
	{
		level = SIMON_LEVEL_BIG;
		untouchable = 0;
	}
	virtual void SitDown();
	virtual void ResetSitDown();
	virtual void attack();
	virtual void resetAttack();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	bool GetAttack() { return this->isAttack; };

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};