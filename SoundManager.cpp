#include "SoundManager.h"
CSoundChoose::CSoundChoose()
{
	audio = new GAudio();
	//Thư mục music
	audio->Init_DirectSound(G_hWnd);
	IntroMenu = audio->LoadSound("Sounds\\music\\Title_Theme_Prelude.wav");
	StartIntro = audio->LoadSound("Sounds\\music\\Game_Start_Prologue.wav");
	ChooseMenu = audio->LoadSound("Sounds\\sound\\select.wav");
	Stage1 = audio->LoadSound("Sounds\\music\\Stage_01_Vampire_Killer.wav");
	Stage2 = audio->LoadSound("Sounds\\music\\Stage_04_Stalker.wav");
	Life_Lost = audio->LoadSound("Sounds\\music\\Life_Lost.wav");


	Boss_Battle_Poison_Mind = audio->LoadSound("Sounds\\music\\Boss_Battle_Poison_Mind.wav");
	End_Game = audio->LoadSound("Sounds\\music\\End_Game.wav");
	Game_Over = audio->LoadSound("Sounds\\music\\Game_Over.wav");
	Game_Start_Prologue = audio->LoadSound("Sounds\\music\\Game_Start_Prologue.wav");
	Life_Lost = audio->LoadSound("Sounds\\music\\Life_Lost.wav");
	Stage_Clear = audio->LoadSound("Sounds\\music\\Stage_Clear.wav");
	Title_Theme_Prelude = audio->LoadSound("Sounds\\music\\Title_Theme_Prelude.wav");

	//Thư mục sound
	collectitem = audio->LoadSound("Sounds\\sound\\collectitem.wav");
	collectweapon = audio->LoadSound("Sounds\\sound\\collectweapon.wav");
	decreaseweaponusepoint = audio->LoadSound("Sounds\\sound\\decreaseweaponusepoint.wav");
	fallcastle = audio->LoadSound("Sounds\\sound\\fallcastle.wav");
	falling = audio->LoadSound("Sounds\\sound\\falling.wav");
	fallingdownwatersurface = audio->LoadSound("Sounds\\sound\\fallingdownwatersurface.wav");
	getscoretimer = audio->LoadSound("Sounds\\sound\\getscoretimer.wav");;
	getscoreweapon = audio->LoadSound("Sounds\\sound\\getscoreweapon.wav");
	hit = audio->LoadSound("Sounds\\sound\\hit.wav");
	hitcannon = audio->LoadSound("Sounds\\sound\\hitcannon.wav");
	holycross = audio->LoadSound("Sounds\\sound\\holycross.wav");
	holywater = audio->LoadSound("Sounds\\sound\\holywater.wav");
	opendoor = audio->LoadSound("Sounds\\sound\\opendoor.wav");
	pause = audio->LoadSound("Sounds\\sound\\pause.wav");
	select = audio->LoadSound("Sounds\\sound\\select.wav");
	splashwater = audio->LoadSound("Sounds\\sound\\splashwater.wav");
	stoptimer = audio->LoadSound("Sounds\\sound\\stoptimer.wav");
	usingwhip = audio->LoadSound("Sounds\\sound\\usingwhip.wav");
}

void CSoundChoose::PlaySoundChoose(int so)
{
	switch (so)
	{
	case 1: //Khi ăn một item mới
	{
		audio->PlaySound(collectitem);
	}break;
	case 2: //Khi ăn một vũ khí (Item)
	{
		audio->PlaySound(collectweapon);
	}break;
	case 3: //Vũ khí ăn tăng dài hơn
	{
		audio->PlaySound(decreaseweaponusepoint);
	}break;
	case 4:
	{
		audio->PlaySound(fallcastle);
	}break;
	case 5:
	{
		audio->PlaySound(falling);
	}break;
	case 6:
	{
		audio->PlaySound(fallingdownwatersurface);
	}break;
	case 7: //T
	{
		audio->PlaySound(getscoretimer);
	}break;
	case 8:
	{
		audio->PlaySound(getscoreweapon);
	} break;
	case 9: //Khi quánh trúng
	{
		audio->PlaySound(hit);
	} break;
	case 10:
	{
		audio->PlaySound(hitcannon);
	} break;
	case 11: //Cây thánh giá
	{
		audio->PlaySound(holycross);
	} break;
	case 12: // Lọ nước thánh
	{
		audio->PlaySound(holywater);
	} break;
	case 13: //Âm lúc mở cửa
	{
		audio->PlaySound(opendoor);
	} break;
	case 14:
	{
		audio->PlaySound(pause);
	} break;
	case 15: //âm chọn menu
	{
		audio->PlaySound(select);
	} break;
	case 16: //
	{
		audio->PlaySound(splashwater);
	} break;
	case 17: //Tính thời gian
	{
		audio->PlaySound(stoptimer);
	} break;
	case 18: //Sử dụng roi
	{
		audio->PlaySound(usingwhip);
	} break;
	default:
	{
	} break;
	}
}

void CSoundChoose::StopSound()
{
	audio->StopSound(IntroMenu);
	audio->StopSound(Stage1);
	audio->StopSound(Stage2);
	audio->StopSound(StartIntro);
	audio->StopSound(Boss_Battle_Poison_Mind);
}

void CSoundChoose::PlayMusicChoose(int so)
{
	switch (so)
	{
	case -1: //Intro Menu
	{
		audio->LoopSound(IntroMenu);
	}break;
	case -10://Âm khi chọn một Play hoặc exit chỗ intro menu
	{
		audio->PlaySound(ChooseMenu);
	} break;
	case 0: //Intro tự động đi sau khi chọn menu play
	{
		audio->PlaySound(StartIntro);
	}break;
	case 1: //Intro chạy xuyên suốt Màn 1
	{
		audio->LoopSound(Stage1);
	}break;
	case 11: //Intro chạy lúc bắt đầu quánh Boss
	{
		audio->LoopSound(Boss_Battle_Poison_Mind);
	}break;
	case 2: //Intro chạy  xuyên suốt Màn 2
	{
		audio->LoopSound(Stage2);
	}break;
	case 4: //Life Lost
	{
		audio->PlaySound(Life_Lost);
	}break;
	default:
	{}break;
	}
}