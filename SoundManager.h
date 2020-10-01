#pragma once
#include "GAudio.h"
class CSoundChoose
{
private:
	//Thư mục music
	GAudio* audio;
	GSound* IntroMenu;
	GSound* StartIntro;
	GSound* ChooseMenu;
	GSound* Stage1;
	GSound* Stage2;
	GSound* Boss_Battle_Poison_Mind;
	GSound* End_Game;
	GSound* Game_Over;
	GSound* Game_Start_Prologue;
	GSound* Life_Lost;
	GSound* Stage_Clear;
	GSound* Title_Theme_Prelude;


	//Thư mục sound
	GSound* collectitem;
	GSound* collectweapon;
	GSound* decreaseweaponusepoint;
	GSound* fallcastle;
	GSound* falling;
	GSound* fallingdownwatersurface;
	GSound* getscoretimer;
	GSound* getscoreweapon;
	GSound* hit;
	GSound* hitcannon;
	GSound* holycross;
	GSound* holywater;
	GSound* opendoor;
	GSound* pause;
	GSound* select;
	GSound* splashwater;
	GSound* stoptimer;
	GSound* usingwhip;


public:
	void PlaySoundChoose(int so);
	void PlayMusicChoose(int so);
	void StopSound();
	CSoundChoose();
	~CSoundChoose();
};