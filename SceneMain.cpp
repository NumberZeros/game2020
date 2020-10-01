#include "SceneMain.h"
#include "Map.h"
SceneMain::SceneMain(int _nCmdShow) : CGame(_nCmdShow)
{
}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));
	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	maps->DrawMap(cam, State);
	minT++;
	if (minT > 30)
	{
		score->Calculator1Sec();
		minT = -1;
	}
	if (State == -1) {
		RenderMenu(t);
	}
	else if (State == 0) {
		RenderIntro(t);
	}
}


void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
}
void SceneMain::LoadOther()
{
}
void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
}

void SceneMain::LoadMap1()
{
	//
}

int SceneMain::EndScene1()
{
	sound->StopSound();
	EndingScene = 1;
	//simon->Go();
	//simon->SetAnimation(1.5, 0, 60);
	test = G_MapWidth - 150;
	if (simon->getx() >= test) return 1;
	return 0;
}

void SceneMain::LoadMap2()
{
}
//Màn 2 chuyển cổng thứ 1(QT2b)
void SceneMain::LoadMap21()
{
}
//Màn 2 chuyển cổng thứ 2 (QT2c)
void SceneMain::LoadMap22()
{
}
void SceneMain::LoadMap3()
{
}
//Load QT3b
void SceneMain::LoadMap31()
{
}
//Load QT3c
void SceneMain::LoadMap32()
{
}
//Load QT3d
void SceneMain::LoadMap33()
{
}
//Load QT3e
void SceneMain::LoadMap34()
{
}
//Load QT3f
void SceneMain::LoadMap35()
{

}
void SceneMain::RenderMenu(int t)
{
}

void SceneMain::RenderIntro(int t)
{
}

void SceneMain::RenderStage(LPDIRECT3DDEVICE9 d3ddv, int t)
{

}
//////////////////////////////////////////
//Source code thêm hàm UpdateObject(Tiền updated)
void SceneMain::UpdateObject(GCamera * cam, int t){
}

void SceneMain::OnKeyDown(int KeyCode)
{
}

void SceneMain::CollisionState(int State)
{
}

void SceneMain::OpenTheGate()
{
}

void SceneMain::MoveCamera(bool up, bool down)
{
}
void SceneMain::MoveDownCamera()
{
}
void SceneMain::MoveUpCamera()
{
}
SceneMain::~SceneMain(void)
{

}

void SceneMain::FlashAnimation()
{
}

void SceneMain::SetDieAllEnemy()
{
}