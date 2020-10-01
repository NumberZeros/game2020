#ifndef _H_CBATBOSS_
#define _H_CBATBOSS_
#include "Object.h"
#include "Simon.h"

#define BOSSBAT_IMAGE_FILE "Resources/boss/0.png"
#define BOSSBAT_FRAME_NRM 70
#define BOSSBAT_FRAME_ATK 30
#define BOSSBAT_STOP_IMAGE 0

#define BOSSBAT_VX 4.0f

#define BOSSBAT_GRAVITY 20
#define BOSSBAT_FALL 180
#define BOSSBAT_VX_DAMAGED 150
#define BOSSBAT_VY_DAMAGED 450
class CBatBoss : public CObject
{
	int Dy;
	int WaitingTime;
	int WT;
	int Status;
	float sm_x, sm_y;
	float y_before;
	int sm_Trend;
	float x1, y1;// vi tri luc dau
	float x2, y2;// vi tri luc sau
	float a, b;//gia toc dau sau
	int bat_x[3];
	int bat_y[3];
public:
	CBatBoss(int x1, int y1, int h1, int w1);
	~CBatBoss() {};
	virtual	void Update(GCamera* cam,int t);
	virtual void Draw(GCamera * cam);
	virtual void Go();
	virtual void GetSMPositionForBoss(float x, float y, int Trend);
	float FindX();
	float FindY();
	float FindX(GCamera *camera);
	float FindY(GCamera *camera);
	virtual Box GetBox(GCamera *camera);
};
#endif // !_H_CBATBOSS_
