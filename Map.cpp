#include "Map.h"
////Xem lại hàng 13 ReadmMap chỗ biến i
Map::Map(int State)
{
	LoadMap(State);
}

Map::~Map()
{
	
}

void Map::ReadMap(char * filename, int State)
{
	ifstream file;
	file.open(filename, ios::in);
	//int i = 0;
	switch (State)
	{
	case 1: ColumnMatrix = 48; break;
	case 2: ColumnMatrix = 176; fit = 96; break;
	case 3: ColumnMatrix = 128; fit = 96; break;
	default : ; break;
	}
	
	while (!file.eof())
	{
		for (int j = 0; j < ColumnMatrix;j++)
		{
			file >> TileMap[RowMatrix][j];
		}
		RowMatrix++;
	}
	int a = RowMatrix;
}

void Map::LoadMap(int State)
{
	switch (State)
	{
	case -1:
	{
		GTTile = new GTexture("./Resources/mainmenu1.png");
	}break;
	case 0:
	{
		GTTile = new GTexture("Resources/intro.png");
	}break;
	case 1:
	{
		ReadMap("Resources/Maps/stage1.txt", State);
		GTTile = new GTexture("./Resources/Maps/stage1.png", 49, 1, 49);
	}break;
	case 2:
	{
		ReadMap("Resources/Maps/stage2.txt",State);
		GTTile = new GTexture("./Resources/Maps/stage2.png", 114, 1, 114);
	}break;
	case 3:
	{
		ReadMap("Resources/Maps/stage3.txt", State);
		GTTile = new GTexture("./Resources/Maps/stage3.png", 63, 1, 63);
	}break;
	}
	ScreenColumn = (G_ScreenWidth) / GTTile->FrameHeight + 2;
	ScreenRow = (G_ScreenHeight) / GTTile->FrameHeight;
	G_MapWidth = (GTTile->FrameHeight)*(ColumnMatrix*(State > 0) + (State == 0));//dùng ở hàm SceneMain.cpp
	//G_MapHeight = (GTTile->FrameHeight)*(RowMatrix*(State > 0) + (State == 0));
	GSTile = new GSprite(GTTile, 0);
}

/*void Map::DrawMap(GCamera* camera, int State)
{
	if (State < 1)
	{
		GSTile->DrawFromTL(0, 0);
		return;
	}
	int x = -(int(camera->viewport.x));
	int y = -(int(camera->viewport.y));
	for (int i = 0; i <RowMatrix; i++)
	{
			for (int j = 0; j < ColumnMatrix; j++)
			{
				GSTile->SelectIndex(TileMap[i][j]);
				GSTile->DrawFromTL(x+j*32,fit+ i*32);					
			}		
	}
}*/

//Vẽ lại hàm drawmap(Updated)
void Map::DrawMap(GCamera* camera, int State)
{
	if (State < 1)
	{
		GSTile->DrawFromTL(0, 0);
		return;
	}
	row = int(camera->viewport.y) / GTTile->FrameHeight;
	column = int(camera->viewport.x) / GTTile->FrameHeight;

	x = -(int(camera->viewport.x) % GTTile->FrameHeight);
	y = (int(camera->viewport.y) % GTTile->FrameHeight);

	for (int i = 0; i < ScreenRow; i++)
	{
		if (y >= fit)
		{
			for (int j = 0; j < ScreenColumn; j++)
			{
				if (!(RowMatrix - row + i < 0 || RowMatrix - row + i >= RowMatrix))
				{
			     GSTile->SelectIndex(TileMap[RowMatrix - row + i][column + j]);
					GSTile->DrawFromTL(x, y);
					x = x + GTTile->FrameHeight;
				}
			}
		}
		y = y + GTTile->FrameHeight;
		x = -int(camera->viewport.x) % GTTile->FrameHeight;
	}
}
void Map::DrawMap2(LPDIRECT3DDEVICE9 d3ddv, GCamera* camera)
{
	x = -(int(camera->viewport.x) % GTTile->FrameHeight);
	y = -(int(camera->viewport.y) % GTTile->FrameHeight);
	for (int i = 4; i < ScreenRow; i++)
	{
		for (int j = 12; j < ScreenColumn; j++)
		{
			if (!(RowMatrix - row + i < 0 || RowMatrix - row + i > RowMatrix))
			{
				GSTile->SelectIndex(TileMap[RowMatrix - row + i][column + j]);
				GSTile->DrawFromTL(x + j*GTTile->FrameHeight, y + i*GTTile->FrameHeight);
			}
		}
		x = -int(camera->viewport.x) % GTTile->FrameHeight;
	}
}





