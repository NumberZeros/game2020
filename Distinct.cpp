#include "Distinct.h"
//NHỚ XÓA CASE 20,0 UPDATE
CDistinct::CDistinct(int io, int x1, int y1, int w1, int h1)
{
	this->whichObj = io;
	switch (whichObj)
	{
	case 0: //Cục gạch ảo, Simon đứng trên cục này
	{
				brick = new CBrick(x1, y1 + AutoFit, w1, h1);
	}break;
	case 1: //Cầu Thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 2: //Cầu Thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 3: //Cầu thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 4: //Cầu thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 5: //Đèn cầy lớn
	{
				lcandle = new CLCandle(x1, y1 + AutoFit, w1, h1);
	}break;
	case 6: //Đèn cầy nhỏ
	{
				mcandle = new CMCandle(x1, y1 + AutoFit, w1, h1);
	}break;
	case 7: //Con chó
	{
				dog = new CDog(x1, y1 + AutoFit, w1, h1);
	}break;
	case 8: //Con cá
	{
				fish = new CFish(x1, y1 + AutoFit, w1, h1);
				fish->setIsDie(1);
	}break;
	case 9: //Con dơi nhỏ (số 0)
	{
				bat = new CBat(x1, y1 + AutoFit, w1, h1);
	}break;
	case 10: //Con ma
	{
				 ghost = new CGhost(x1, y1 + AutoFit, w1, h1);
	}break;
	case 11: //Boss màn 1 (Số 0)
	{
				 batboss = new CBatBoss(x1, y1 + AutoFit, w1, h1);
	}break;
	case 12: //Cái đầu (Số 06) bay bay
	{
				 medusa = new CMedusa(x1, y1 + AutoFit, w1, h1);
	}break;
	case 13: //Lính nhỏ
	{
				 sironman = new CSIronMan(x1, y1 + AutoFit, w1, h1);
	}break;
	case 14: // Đầu lâu 08
	{
				 dragonhead = new CDragonHead(x1, y1 + AutoFit, w1, h1);
	}break;
	case 15: //Boss medusa 01
	{
				 bossmedusa = new CBossMedusa(x1, y1 + AutoFit, w1, h1);
	}break;
	case 16: //Gach đưa qua lại 9
	{

				 brick9 = new CBrick9(x1, y1 + AutoFit, w1, h1);
	}break;
	case 17: //Trap dập xuống nếu bước qua
	{
				 trap = new CTrap(x1, y1 + AutoFit, w1, h1);
	}break;
	case 20: //CHuyển màn 1
	{
				 vir_20 = new CVir_20(x1, y1 + AutoFit, w1, h1);
	}break;
	//case 21:  // Cổng chuyển màn 20->24
	//{
	//	GTObject = new GTexture("./Resources/ground/Gate.png");
	//	GSObject = new GSprite(GTObject, 5);
	//}break;
	case 22:
	{
			   door = new CDoor(x1, y1 + AutoFit, w1, h1);
	}break;

	case 29:
	{
			   brick2 = new CBrick2(x1, y1 + AutoFit, w1, h1);
	}break;
	case 30:
	{
			   brick1 = new CBrick1(x1, y1 + AutoFit, w1, h1);
	}break;
	case 31:
	{
			   brick3 = new CBrick3(x1, y1 + AutoFit, w1, h1);
	}break;
	case 41:
	{
			waterdie = new CWaterDie(x1, y1 + AutoFit, w1, h1);
	}break;
	default:
	{

	}break;
	}

}

CDistinct::~CDistinct()
{

}

void CDistinct::Draw(GCamera * cam)
{
	switch (whichObj)
	{
	case 0: //Cục gạch ảo, Simon đứng trên cục này
		//brick->Draw(cam);
		break;
	case 1:
		//stair->Draw(cam);
		break;
	case 2:
		stair->Draw(cam);
		break;
	case 3:
		//stair->Draw(cam);
		break;
	case 4:
		stair->Draw(cam);
		break;
	case 5:
	{
			  if (lcandle->getIsDie() == 0) lcandle->Draw(cam);
	}break;
	case 6:
	{
			  if (mcandle->getIsDie() == 0)mcandle->Draw(cam);
	}break;
	case 7:
	{
			  if (dog->getIsDie() == 0)dog->Draw(cam);
	}break;
	case 8:
	{
			  if (fish->getIsDie() == 0)fish->Draw(cam);
	}break;
	case 9:
	{
			  if (bat->getIsDie() == 0)bat->Draw(cam);
	}break;
	case 10:
	{
			   if (ghost->getIsDie() == 0)ghost->Draw(cam);
	}break;
	case 11:
	{
		if (batboss->getIsDie() == 0)batboss->Draw(cam);
	}
		break;
	case 12:
	{
			   if (medusa->getIsDie() == 0)
				   medusa->Draw(cam);
	}break;
	case 13:
	{
			   if (sironman->getIsDie() == 0)sironman->Draw(cam);
	}break;
	case 14:
	{
			   if (dragonhead->getIsDie() == 0)dragonhead->Draw(cam);
	}break;
	case 15:
	{
			   if (bossmedusa->getIsDie() == 0)bossmedusa->Draw(cam);
	}break;
	case 16:
	{
			   if (brick9->getIsDie() == 0)brick9->Draw(cam);
	}break;
	case 17:
	{
			   if (trap->getIsDie() == 0)trap->Draw(cam);
	}break;
	case 22:
	{
			   if (door->getIsDie() == 0)
				   door->Draw(cam);
	}break;
	case 29:
	{
			   //if (brick2->getIsDie() == 0)
			   brick2->Draw(cam);
	}break;
	case 30:
	{
			   //if (brick2->getIsDie() == 0)
			   brick1->Draw(cam);
	}break;
	case 31:
	{
			   //if (brick2->getIsDie() == 0)
			   brick3->Draw(cam);
	}break;
	case 41:
	{
		//if (brick2->getIsDie() == 0)
		//waterdie->Draw(cam);
	}break;
	default:
	{

	}break;
	}
}

void CDistinct::Update(GCamera *camera, int t)
{
	switch (whichObj)
	{
	case 5: //Cục gạch ảo, Simon đứng trên cục này
	{
				if (lcandle->getIsDie() == 0) lcandle->Update(t);
	}break;
	case 6: //Đèn cầy
	{
				if (mcandle->getIsDie() == 0) mcandle->Update(t);
	}break;
	case 7: //Con 
	{
				if (dog->getIsDie() == 0) dog->Update(t);
	}break;
	case 8:
	{
			  if (fish->getIsDie() == 0)fish->Update(t);
	}break;
	case 9: //Con dơi
	{
				if (bat->getIsDie() == 0)
				{
					if (bat->getx() < camera->viewport.x + 470) bat->Update(t);
				}
	}break;
	case 10: //Con ma
	{
				 if (ghost->getIsDie() == 0) ghost->Update(t);
	}break;
	case 11:
	{
		if (batboss->getIsDie() == 0)
			   batboss->Update(camera, t);
	}
		break;
	case 12: //Con medusa
	{
				 if (medusa->getIsDie() == 0) medusa->Update(camera->viewport.x, t);
	}break;
	case 13: //Con sỉonman
	{
				 if (sironman->getIsDie() == 0) sironman->Update(t);
	}break;
	case 14: //Đầu rồng
	{
				 if (dragonhead->getIsDie() == 0) dragonhead->Update(t);
	}break;
	case 15: //BossMedusa
	{
				 if (bossmedusa->getIsDie() == 0) bossmedusa->Update(camera, t);
	}break;
	case 16: //
	{
				 if (brick9->getIsDie() == 0) brick9->Update(t);
	}break;
	case 17:
	{
			   if (trap->getIsDie() == 0) trap->Update(camera, t);
	}break;
	case 22:
	{
			   if (door->getIsDie() == 0) door->Update(t);
	}break;
	case 29:
	{
			   if (brick2->getIsDie() == 0)
			   {
				   brick2->Update(t);
			   }
	}break;
	case 30:
	{
			   if (brick1->getIsDie() == 0)
			   {
				   brick1->Update(t);
			   }
	}break;
	case 31:
	{
			   if (brick3->getIsDie() == 0)
			   {
				   brick3->Update(t);
			   }
	}break;
	default:
	{

	}break;
	}
}

Box CDistinct::GetBox(GCamera *camera) {
	switch (whichObj) {
	case 0:
	{
			  D3DXVECTOR2 pos = camera->Transform(brick->getx() - brick->getw() / 2, brick->gety() + brick->geth() / 2);
			  return Box(pos.x, pos.y, brick->getw(), brick->geth(), 0, 0);
	}break;
	case 1: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 2: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 3: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 4: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 5:
	{
			  D3DXVECTOR2 pos = camera->Transform(lcandle->getx() - lcandle->getw() / 2, lcandle->gety() + lcandle->geth() / 2);
			  return Box(pos.x, pos.y, lcandle->getw(), lcandle->geth(), 0, 0);
	}break;
	case 6:
	{
			  return mcandle->GetBox(camera);
	}break;
	case 7:
	{
			  D3DXVECTOR2 pos = camera->Transform(dog->getx() - dog->getw() / 2, dog->gety() + dog->geth() / 2);
			  return Box(pos.x, pos.y, dog->getw(), dog->geth(), dog->getVx(), -dog->GetVy());
	}break;
	case 8:
	{
			  return fish->GetBox(camera);
	}break;
	case 9:
	{
			  return bat->GetBox(camera);
	}break;
	case 10:
	{
			   return ghost->GetBox(camera);
	}break;
	case 11: {
		return batboss->GetBox(camera);
	}break;
	case 12:
	{
			   return medusa->GetBox(camera);
	}break;
	case 13:
	{
			   return sironman->GetBox(camera);
			   //return Box(0, 0, 0, 0, 0, 0);
	}break;
	case 14:
	{
			   return dragonhead->GetBox(camera);
	}break;
	case 15:
	{
			   return bossmedusa->GetBox(camera);
	}break;
	case 16:
	{
			   return brick9->GetBox(camera);
	}break;
	case 17:
	{
			   return trap->GetBox(camera);
	}break;
	case 20:
	{
			   //return vir_20->GetBox(camera);
			   D3DXVECTOR2 pos = camera->Transform(vir_20->getx() - vir_20->getw() / 2, vir_20->gety() + vir_20->geth() / 2);
			   return Box(pos.x, pos.y, vir_20->getw(), vir_20->geth(), 0, 0);
	}break;
	case 22:
	{
			   return door->GetBox(camera);
	}break;
	case 29:
	{
			   return brick2->GetBox(camera);
	}break;
	case 30:
	{
			   return brick1->GetBox(camera);
	}break;
	case 31:
	{
			   return brick3->GetBox(camera);
	}break;
	case 41:
	{
		D3DXVECTOR2 pos = camera->Transform(waterdie->getx() - waterdie->getw() / 2, waterdie->gety() + waterdie->geth() / 2);
		return Box(pos.x, pos.y, waterdie->getw(), waterdie->geth(), 0, 0);
	}break;
	default:
	{
			   return Box(0, 0, 0, 0, 0, 0);
	}break;
	}
}
int CDistinct::getObjX() {
	switch (whichObj) {
	case 0:return brick->getx();
		break;
	case 1:return stair->getx();
		break;
	case 2:return stair->getx();
		break;
	case 3: return stair->getx();
		break;
	case 4: return stair->getx();
		break;
	case 5:
		return lcandle->getx();
		break;
	case 6:
		return mcandle->getx();
		break;
	case 7:
		return dog->getx();
		break;
	case 8:
		return fish->getx();
		break;
	case 9:
		return bat->getx();
		break;
	case 10:
		return ghost->getx();
		break;
	case 11:
		return batboss->getx();
		break;
	case 12:
		return medusa->getx();
		break;
	case 13:
		return sironman->getx();
		break;
	case 14:
		return dragonhead->getx();
		break;
	case 15:
		return bossmedusa->getx();
		break;
	case 16:
		return brick9->getx();
		break;
	case 17:
		return trap->getx();
		break;
	case 22:
		return door->getx();
		break;
	case 29:
		return brick2->getx();
		break;
	case 30:
		return brick1->getx();
		break;
	case 31:
		return brick3->getx();
		break;
	}
}
int CDistinct::getObjY() {
	switch (whichObj) {
	case 0:
		return brick->gety();
		break;
	case 1: return stair->gety();
		break;
	case 2: return stair->gety();
		break;
	case 3: return stair->gety();
		break;
	case 4: return stair->gety();
		break;
	case 7:
		return dog->gety();
		break;
	case 8:
		return fish->gety();
		break;
	case 9:
		return bat->gety();
		break;
	case 10:
		return ghost->gety();
		break;
	case 11:
		return batboss->gety();
		break;
	case 12:
		return medusa->gety();
		break;
	case 13:
		return sironman->gety();
		break;
	case 14:
		return dragonhead->gety();
		break;
	case 15:
		return bossmedusa->gety();
		break;
	case 16:
		return brick9->gety();
		break;
	case 17:
		return  trap->gety();
		break;
	case 29:
		return  brick2->gety();
		break;
	case 30:
		return  brick1->gety();
		break;
	case 31:
		return  brick3->gety();
		break;
	}
}
int CDistinct::getObjH() {
	switch (whichObj) {
	case 0:
		return brick->geth();
		break;
	case 7:
		return dog->geth();
		break;
	case 13:
		return sironman->geth();
		break;
	case 14:
		return dragonhead->geth();
		break;
	case 16:
		return brick9->geth();
		break;
	case 17:
		return trap->geth();
		break;
	case 29:
		return brick2->geth();
		break;
	case 30:
		return brick1->geth();
		break;
	case 31:
		return brick3->geth();
		break;
	}
}

int CDistinct::getObjW() {
	switch (whichObj) {
	case 0:
		return brick->getw();
		break;
	case 7:
		return dog->getw();
		break;
	case 8:
		return fish->getw();
		break;
	case 14:
		return dragonhead->getw();
		break;
	case 16:
		return brick9->getw();
		break;
	case 17:
		return trap->getw();
		break;
	}
}

int	CDistinct::getIsDie()
{
	switch (whichObj)
	{
	case 5:
	{
			  return lcandle->getIsDie();
	}break;
	case 6:
	{
			  return mcandle->getIsDie();
	}break;
	case 7:
	{
			  return dog->getIsDie();
	}break;
	case 8:
	{
			  return fish->getIsDie();
	}break;
	case 9:
	{
			  return bat->getIsDie();
	}break;
	case 10:
	{
			   return ghost->getIsDie();
	}break;
	case 11:
	{
		return batboss->getIsDie();
	}break;
	case 12:
	{
			   return medusa->getIsDie();
	}break;
	case 13:
	{
			   return sironman->getIsDie();
	}break;
	case 14:
	{
			   return dragonhead->getIsDie();
	}break;
	case 15:
	{
			   return bossmedusa->getIsDie();
	}break;
	case 17:
	{
			   return trap->getIsDie();
	}break;
	case 29:
	{
			   return brick2->getIsDie();
	}break;
	case 30:
	{
			   return brick1->getIsDie();
	}break;
	case 31:
	{
			   return brick3->getIsDie();
	}break;
	default:
	{

	}break;
	}
}


void CDistinct::setIsDie(bool a)
{
	switch (whichObj)
	{

	case 5:
	{
			  return lcandle->setIsDie(a);
	}break;
	case 6:
	{
			  return mcandle->setIsDie(a);
	}break;
	case 7:
	{
			  return dog->setIsDie(a);
	}break;
	case 8:
	{
			  return fish->setIsDie(a);
	}break;
	case 9:
	{
			  return bat->setIsDie(a);
	}break;
	case 10:
	{
			   return ghost->setIsDie(a);
	}break;
	case 11:
	{
		return batboss->setIsDie(a);
	}break;
	case 12:
	{
			   return medusa->setIsDie(a);
	}break;
	case 13:
	{
			   return sironman->setIsDie(a);
	}break;
	case 14:
	{
			   return dragonhead->setIsDie(a);
	}break;
	case 15:
	{
			   return bossmedusa->setIsDie(a);
	}break;
	case 17:
	{
			   return trap->setIsDie(a);
	}break;
	case 20: //NHỚ PHẢI XÓA THẰNG NÀY
	{
				 return vir_20->setIsDie(a);
	}break;

	default:
	{

	}break;
	}
}

void  CDistinct::Fall() {
	switch (whichObj) {
	case 7:
	{
			  return dog->Fall();
			  break;
	}
	case 8:
	{
			  return fish->Fall();
	}break;
	case 10:
	{
			   return ghost->Fall();
	}break;
	/*case 12:
	{
	return medusa->Fall();
	break;
	}*/
	case 13:
	{
			   return sironman->Fall();
			   break;
	}
	case 14:
	{
			   return dragonhead->Fall();
			   break;
	}
	}
}

void CDistinct::Jump() {
	switch (whichObj) {
	case 7:
		return dog->Jump();
		break;
	case 8:
		return fish->Jump();
		break;
	}
}
void CDistinct::Go() {
	switch (whichObj) {
	case 7:
		return dog->Go();
		break;
	case 8:
		return fish->Go();
		break;
	case 11:
		return batboss->Go();
		break;
	case 14:
		return dragonhead->Go();
		break;
	case 15:
		return bossmedusa->Go();
		break;
	case 17:
		return trap->Go();
		break;
	}
}

void CDistinct::StopFall(float y)
{
	switch (whichObj) {
	case 10:
		return ghost->StopFall(y);
		break;
	case 7:
		return dog->StopFall(y);
		break;
	case 8:
		return fish->StopFall(y);
		break;
	case 12:
	{
			   return medusa->StopFall(y);
			   break;
	}
	case 13:
		return sironman->StopFall(y);
		break;
	case 14:
		return dragonhead->StopFall(y);
		break;
	}
}

void CDistinct::moveRigh() {
	switch (whichObj) {
	case 7:
		return dog->MoveRigh();
		break;
	}
}

int CDistinct::getIsGoing() {
	switch (whichObj)
	{
	case 7:
		return dog->getIsGoing();
		break;
	case 8:
		return fish->getIsGoing();
		break;
	case 10:
		return ghost->getIsGoing();
		break;
	case 11:
		return batboss->getIsGoing();
		break;
	case 15:
		return bossmedusa->getIsGoing();
		break;
	}
}
int CDistinct::getIsJumping() {
	switch (whichObj)
	{
	case 8:
		return fish->getIsJumping();
		break;
	}
}
int CDistinct::getIsFalling() {
	switch (whichObj)
	{
	case 7:
		return dog->getIsFalling();
		break;
	case 8:
		return fish->getIsFalling();
		break;
	}
}

void CDistinct::setX(int a)
{
	switch (whichObj)
	{
	case 0:
	{
			  brick->setx(a);
	}break;
	case 10:
	{
			   ghost->setx(a);
	}break;
	}
}


int CDistinct::getTimeFall() {
	switch (whichObj)
	{
	case 7:
	{
			  return dog->timeFall;
	}break;
	}
}

void CDistinct::settrend(int trend) {
	switch (whichObj) {
	case 1: stair->setTrend(trend);
		break;
	case 2: stair->setTrend(trend);
		break;
	case 3: stair->setTrend(trend);
		break;
	case 4: stair->setTrend(trend);
		break;
	case 10:ghost->setTrend(trend);
		break;
	case 12:medusa->setTrend(trend);
		break;
	case 13:sironman->setTrend(trend);
		break;
	case 14:dragonhead->setTrend(trend);
		break;

	}
}
int CDistinct::gettrend() {
	switch (whichObj) {
	case 1: return stair->getTrend();
		break;
	case 2: return stair->getTrend();
		//break;
	case 3: return stair->getTrend();
		break;
	case 4: return stair->getTrend();
		break;
	case 8: return fish->getTrend();
		break;
	case 10: return ghost->getTrend();
		break;
	case 12:medusa->getTrend();
		break;
	case 13:sironman->getTrend();
		break;
	case 14:dragonhead->getTrend();
		break;
	case 16:brick9->getTrend();
		break;
	}
}

int CDistinct::getWater() {
	switch (whichObj)
	{
	case 8:
	{
			  return fish->water;
	}break;
	}
}
void CDistinct::setWater(int a) {
	switch (whichObj)
	{
	case 8:
	{
			  fish->water = a;
	}break;
	}
}
void CDistinct::breakBrick()
{
	switch (whichObj)
	{
	case 29:
	{
			  brick2->brickbreak++;
	}break;
	case 30:
	{
			   brick1->brickbreak++;
	}break;
	case 31:
	{
			   brick3->brickbreak++;
	}break;
	}
}
int CDistinct::getBreakBrick(){
	switch (whichObj)
	{
	case 29:
	{
			   return brick2->brickbreak;
	}break;
	case 30:
	{
			   return brick1->brickbreak;
	}break;
	case 31:
	{
			   return brick3->brickbreak;
	}break;
	}
}

void CDistinct::setMaxMin(float a, float b) {
	switch (whichObj)
	{
	case 13:
	{
			   return sironman->setMaxMin(a, b);
	}break;
	}
}
int CDistinct::getMax(){
	switch (whichObj)
	{
	case 13:
	{
			   return sironman->getMax();
	}break;
	}
}
int CDistinct::getMin(){
	switch (whichObj)
	{
	case 13:
	{
			   return sironman->getMin();
	}break;
	}
}
float CDistinct::getVx()
{
	switch (whichObj)
	{
	case 16:
	{
			   return brick9->getVx();
	}break;
	default:
	{

	}break;
	}
}

void CDistinct::GetSMPositionForBoss(float x){
	switch (whichObj){
	case 15:
	{
			   return bossmedusa->GetSMPositionForBoss(x);
	}break;
	}
}
void CDistinct::GetSMPositionForBoss(float x, float y, int Trend) {
	switch (whichObj) {
	case 11:
	{
			   return batboss->GetSMPositionForBoss(x, y, Trend);
	}break;
	}
}
int CDistinct::CreateWeapon()
{
	switch (whichObj){
	case 8:
	{
			  return fish->CreateWeapon();
	}break;
	case 14:
	{
			   return dragonhead->CreateWeapon();
	}break;
	case 15:
	{
			   return bossmedusa->CreateWeapon();
	}break;
	}
}
void CDistinct::Attack(Weapon *weapon)
{
	switch (whichObj){
	case 8:
	{
			  return fish->Attack(weapon);
	}break;
	case 14:
	{
			   return dragonhead->Attack(weapon);
	}break;
	case 15:
	{
			   return bossmedusa->Attack(weapon);
	}break;
	}
}

void CDistinct::SetHurt(int i){
	switch (whichObj){
	case 11:
	{
		return batboss->SetHurt(i);
	}break;
	case 15:
	{
		return bossmedusa->SetHurt(i);
	}break;
	}
}
int CDistinct::GetHurt(){
	switch (whichObj){
	case 11:
	{
		return batboss->GetHurt();
	}break;
	case 15:
	{
	   return bossmedusa->GetHurt();
	}break;
	}
}
int CDistinct::getHealth() {
	switch (whichObj) {
	case 13:
	{
		return sironman->health;
	}
	case 14:
	{
		return dragonhead->health;
	}break;
	}
}
void CDistinct::setHealth() {
	switch (whichObj) {
	case 13:
	{
		sironman->health--;
	} break;
	case 14:
	{
		dragonhead->health--;
	}break;
	}
}