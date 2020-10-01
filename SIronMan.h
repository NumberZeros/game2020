#pragma once
#include "Object.h"
#define SIronMan_GRAVITY 1
class CSIronMan  : public CObject
{
	int Min =0 , Max = 0;
public:
	int health;
	CSIronMan (int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	virtual void Draw(GCamera * cam);
	virtual void StopFall(float y);
	virtual void Go();
	void setMaxMin(int a, int b);
	int getMax();
	int getMin();
	~CSIronMan ();
};