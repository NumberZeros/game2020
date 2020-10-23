#pragma once
#include "Simon.h"
#include "Weapon.h"

class CScence {
protected:
	CSimon* simon;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);


public:

	CScence();

	virtual void ClearAll(LPCWSTR a);

	virtual void Load(LPCWSTR sceneFilePath);
	virtual void LoadObject();
	virtual void LoadMap(LPCWSTR map);
	virtual void LoadBaseObject();
	virtual void SwitchScene(int id);
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
};