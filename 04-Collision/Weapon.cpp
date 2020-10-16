#include "Weapon.h"
#include "Mario.h"
#include <time.h>

CWeapon::CWeapon()
{
	level = 1;
	x = -100;
	y = -100;
	isHidden = true;
}


void CWeapon::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isHidden) return;

	UpdatePositionWithSimon();

	frame == 3 ? isCol = true : isCol = false;

	int ani = GetCurrentAnimation();

	if (animations[ani]->get_countAni() > 0)
	{
		animations[ani]->ResetFrame();
		animations[ani]->set_countAni(0);
		isHidden = true;
	}

	if (!isHidden && isCol)
	{
	}
}

void CWeapon::Render()
{

	int ani;
	ani = GetCurrentAnimation();

}
void CWeapon::ResetAttack()
{
	for (unsigned int i = 0; i < animations.size(); i++)
	{
		animations[i]->ResetFrame();
	}
}

void CWeapon::SetState(int state)
{
	CGameObject::SetState(state);
}

int CWeapon::GetCurrentAnimation()
{
	int ani;

	if (state == STATE_ATTACK_RIGHT)
	{
		if (level == 1)
		{
			ani = WEAPON_ANI_1_RIGHT;
		}
		else if (level == 2)
		{
			ani = WEAPON_ANI_2_RIGHT;
		}
		else if (level == 3)
		{
			ani = WEAPON_ANI_3_RIGHT;
		}
	}
	else if (state == STATE_ATTACK_LEFT)
	{
		if (level == 1)
		{
			ani = WEAPON_ANI_1_LEFT;
		}
		else if (level == 2)
		{
			ani = WEAPON_ANI_2_LEFT;
		}
		else if (level == 3)
		{
			ani = WEAPON_ANI_3_LEFT;
		}
	}

	return ani;
}

void CWeapon::SetPosTemp(float xt, float yt)
{
	xx = xt;
	xy = yt;
}

void CWeapon::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;

	if (level != 3)
	{
		if (frame == 1)
		{
			right = left + WEAPON_BBOX_FRAME_1_WIDTH;
			bottom = top + WEAPON_BBOX_FRAME_1_HEIGHT;
		}
		else if (frame == 2)
		{
			right = left + WEAPON_BBOX_FRAME_2_WIDTH;
			bottom = top + WEAPON_BBOX_FRAME_2_HEIGHT;
		}
		else if (frame == 3)
		{
			right = left + WEAPON_BBOX_FRAME_3_WIDTH;
			bottom = top + WEAPON_BBOX_FRAME_3_HEIGHT;
		}
		else
		{
			right = left;
			bottom = top;
		}
	}
	else
	{
		if (frame == 1)
		{

			right = left + WEAPON_BBOX_FRAME_1_WIDTH;
			bottom = top + WEAPON_BBOX_FRAME_1_HEIGHT;
		}
		else if (frame == 2)
		{
			right = left + WEAPON_BBOX_FRAME_2_WIDTH;
			bottom = top + WEAPON_BBOX_FRAME_2_HEIGHT;
		}
		else if (frame == 3)
		{
			right = left + WEAPON_BBOX_FRAME_3_3_WIDTH;
			bottom = top + WEAPON_BBOX_FRAME_3_3_HEIGHT;
		}
		else
		{
			right = left;
			bottom = top;
		}
	}
}

CWeapon* CWeapon::__instance = NULL;
CWeapon* CWeapon::GetInstance()
{
	if (__instance == NULL) __instance = new CWeapon();
	return __instance;
}

void CWeapon::UpdatePositionWithSimon()
{
	int ani;
	ani = GetCurrentAnimation();

	x = xx;
	y = xy;

	if (animations[ani]->GetCurrentFrame() == -1)
	{
		x = -100;
		y = -70;
	}

	if (state == STATE_ATTACK_RIGHT)
	{

	}
	else if (state == STATE_ATTACK_LEFT)
	{
		
	}
}
