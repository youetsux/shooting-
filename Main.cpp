# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	TextureAsset::Register(U"PLAYER", U"images\\ships\\3.png");

	Player* p = new Player;


	while (System::Update())
	{
		p->Update();
		p->Draw();
	}
}


