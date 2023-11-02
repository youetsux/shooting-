#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(Texture& _tex)
	:GameChara(),renderSize_(BULLET_CHR_SIZE),rectSize_(BULLET_RECT_SIZE)
{
	tex_ = _tex; //画像を設定
	pos_ = BULLET_INIT_POS;
	speed_ = BULLET_MOVE_SPEED;
	SetCharaRect(rectSize_);
	moveDir_ = { 0, -1 };
	isAlive_ = false;
}

void Bullet::SetRenderSize(SizeF _rendersize)
{
	renderSize_ = _rendersize;
}

void Bullet::SetBBRectSize(SizeF _rectsize)
{
	rectSize_ = _rectsize;
}

void Bullet::Update()
{
	if (isAlive_) {
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect(rectSize_);
	}
	else
		return;
	//画面外に出たら、BULLET_INIT_POSに位置を戻す
	//ここに
}

void Bullet::Draw()
{
	if (isAlive_) {
		tex_.resized(renderSize_).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
