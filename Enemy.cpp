﻿#include "stdafx.h"
#include "Enemy.h"

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

void Enemy::Shot()
{
}

void Enemy::MoveDown()
{
}

void Enemy::Update()
{
	if (KeySpace.down())
		FlipMove();

	if (isAlive_) {
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect({ ENEMY_RECT_SIZE, ENEMY_RECT_SIZE });
	}
}

void Enemy::Draw()
{
	if (isAlive_) {
		tex_.resized(ENEMY_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
