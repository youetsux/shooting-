#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(Vec2 _pos)
	:GameChara(_pos)
{
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

Enemy::Enemy()
	:GameChara()
{
	pos_ = Scene::Center();
	speed_ = ENEMY_MOVE_SPEED;
	tex_ = TextureAsset(U"ENEMY");
	SetCharaRect(SizeF{ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	moveDir_ = { 1, 0 };
	isAlive_ = true;
}

void Enemy::Initialize()
{
	Texture pGunTex = TextureAsset(U"SHOT2");
	gun_ = new Bullet(pGunTex); //Bulletクラスのインスタンスgun_をせいせい　画像はSHOT1
	gun_->SetRenderSize(ENEMY_BULLET_IMG_SIZE);
	gun_->SetBBRectSize(ENEMY_BULLET_RECT_SIZE);
	gun_->DeActivateMe();
	gun_->SetPosition(BULLET_INIT_POS); //画面の外の邪魔にならない場所に弾をおいておく
	gun_->SetCharaRect(ENEMY_BULLET_RECT_SIZE);
	gun_->SetSpeed(ENEMY_BULLET_MOVE_SPEED);
	gun_->SetMoveDir({ 0,  1 });
	timer_ = new CTimer(ENEMY_SHOT_INTERVAL);
	timer_->StartTimer();
}

void Enemy::Shot()
{
	if (gun_->isActive() == false) {
		gun_->SetPosition(pos_);
		gun_->ActivateMe();
	}
}

void Enemy::MoveDown()
{
	Vec2 downVec{ 0, ENEMY_CHR_SIZE / 4 }; //エネミーのキャラサイズの１／４ぐらいy軸＋方向に動かそう
	pos_ = pos_ + downVec;//下に動くベクトル
}

void Enemy::Update()
{
	if (isAlive_) {
		if (timer_->IsTimeOver())
		{
			Shot();
			timer_->ResetTimer();
		}
		else
		{
			timer_->Update();
		}

		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();

		if (pos_.x - ENEMY_RECT_SIZE / 2 < 0 || pos_.x + ENEMY_RECT_SIZE / 2 > Scene::Width())
		{
			FlipMove();
			MoveDown();
		}
		SetCharaRect({ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	}

	gun_->Update();
}

void Enemy::Draw()
{
	if (gun_->isActive())
		gun_->Draw();

	if (isAlive_) {
		tex_.resized(ENEMY_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
