# include <Siv3D.hpp> // OpenSiv3D v0.6.10
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"


void PlayerBulletVSEnemy(Bullet* _b, Enemy* _e);
void EnemyBulletVSPlayer(Bullet* _b, Player* _p);
void HitCheck(GameChara* _a, GameChara* _b);
vector<Explosion *> bombList;//爆発保存用の配列（行方不明にならないように作っておく）



void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });
	TextureAsset::Register(U"PLAYER", U"images\\ships\\3.png");
	TextureAsset::Register(U"ENEMY", U"images\\ships\\9.png");
	TextureAsset::Register(U"SHOT1", U"images\\shots\\3.png");
	TextureAsset::Register(U"SHOT2", U"images\\shots\\7.png");
	TextureAsset::Register(U"BOOOM", U"images\\explosion.png");



	Player* p = new Player; //動的なインスタンス生成
	p->Initialize(); //プレイヤーの身の回りを初期化する関数

	Enemy* e = new Enemy; //動的なインスタンス生成
	e->Initialize();

	
	while (System::Update())
	{
		for (auto& theI : bombList)
			theI->Update();

		for (auto& theI : bombList)
			theI->Draw();

		//PlayerBulletVSEnemy(p->GetBullet(), e);
		//EnemyBulletVSPlayer(e->GetBullet(), p);
		HitCheck(p->GetBullet(), e);
		HitCheck(e->GetBullet(), p);
		//出来た人は（復習組）、当たり判定の起きた位置に、爆発の画像を貼ってみよう

		p->Update();
		p->Draw();
		e->Update();
		e->Draw();
	}
}


void PlayerBulletVSEnemy(Bullet* _b, Enemy* _e)
{
	if (_b->isActive() == false)
		return;

	if (_b->IsMyRectHit(_e->GetCharaRect()))
	{
		Explosion* e = new Explosion(_e->pos_);
		bombList.push_back(e);
		_b->DeActivateMe();
		_e->DeActivateMe();
		
	}
}

void EnemyBulletVSPlayer(Bullet* _b, Player* _p)
{
	if (_b->isActive() == false)
		return;

	if (_b->IsMyRectHit(_p->GetCharaRect()))
	{
		Explosion* e = new Explosion(_p->pos_);
		bombList.push_back(e);
		_b->DeActivateMe();
		_p->DeActivateMe();
	}
}

void HitCheck(GameChara* _a, GameChara* _b)
{
	if (_a->isActive() == false)
		return;

	if (_a->IsMyRectHit(_b->GetCharaRect()))
	{
		Explosion* e = new Explosion(_b->pos_);
		bombList.push_back(e);
		_a->DeActivateMe();
		_b->DeActivateMe();
	}
}
