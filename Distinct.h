#include "Brick.h"
#include "LCandle.h"
#include "Dog.h"
#include "Ghost.h"
#include "MCandle.h"
#include "Sweet_AABB.h"
#include "Vir_20.h"
#include "Door.h"
#include "CStair.h"
#include "Fish.h"
#include "Brick2.h"
#include "Brick1.h"
#include "Bat.h"
#include "Medusa.h"
#include "SIronMan.h"
#include "Brick9.h"
#include "DragonHead.h"
#include "Trap.h"
#include "BossMedusa.h"
#include "CBatBoss.h"
#include "Simon.h"
#include "Brick3.h"
#include "WaterDie.h"
#pragma once
class CDistinct
{
private:
	int whichObj;	 //Phân biệt obj
public:
	int			getwhichObj() { return whichObj; }
	void		setwhichObj(int x1) { whichObj = x1; }
	CBrick * brick;
	CLCandle *lcandle;
	CMCandle *mcandle;
	CDog *dog;
	CGhost *ghost;
	CVir_20 *vir_20;
	CDoor * door;
	CStair *stair;
	CFish * fish;
	CBat *bat;
	CBrick2 *brick2;
	CMedusa *medusa;
	CSIronMan *sironman;
	CBrick9 *brick9;
	CDragonHead *dragonhead;
	CTrap *trap;
	CBossMedusa* bossmedusa;
	CBatBoss * batboss;
	CBrick1 *brick1;
	CBrick3 *brick3;
	CWaterDie *waterdie;
	//Tiền updated
	bool coliDog;
	bool coliFish;
	bool coliBrick;
	bool endEffect;
	bool enemyDie;
	////////////////////
	CDistinct(int io, int x1, int y1, int w1, int h1);
	void Draw(GCamera * cam);
	void Update(GCamera *camera, int t);
	~CDistinct();
	int			getObjX();
	int			getObjY();
	int			getObjW();
	int			getObjH();
	int			getIsDie();

	void		setX(int a);

	void		setIsDie(bool a);

	virtual void Fall();
	virtual void StopFall(float a);
	virtual void Jump();
	virtual void Go();

	virtual Box GetBox(GCamera *camera);
	////////////////////////(Tiền update)
	void  moveRigh();
	int getIsGoing();
	int getTimeFall();
	int getIsJumping();
	int getIsFalling();
	//dùng cho cầu thang.
	void		settrend(int trend);
	int         gettrend();

	//Hàm mang tính cá nhân
	void		breakBrick();
	int getBreakBrick();
	int getWater();
	void setWater(int a);
	void GetSMPositionForBoss(float x);
	void GetSMPositionForBoss(float x, float y, int Trend);
	int CreateWeapon();
	void Attack(Weapon *weapon);
	void SetHurt(int i);
	int GetHurt();
	void setMaxMin(float a, float b);
	int getMax();
	int getMin();
	float getVx();
	int getHealth();
	void setHealth();
};
