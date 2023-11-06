# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	TextureAsset::Register(U"PLAYER", U"images\\ships\\3.png");
	TextureAsset::Register(U"ENEMY", U"images\\ships\\9.png");
	TextureAsset::Register(U"SHOT1", U"images\\shots\\3.png");
	TextureAsset::Register(U"SHOT2", U"images\\shots\\7.png");


	Player* p = new Player; //動的なインスタンス生成
	p->Initialize(); //プレイヤーの身の回りを初期化する関数


	Enemy* e = new Enemy; //動的なインスタンス生成
	e->Initialize();
	


	while (System::Update())
	{

		p->Update();
		p->Draw();
		e->Update();
		e->Draw();
	}
}


