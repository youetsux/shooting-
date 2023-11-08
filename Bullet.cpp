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
//敵を自動で動くように（左右往復＋ちょっとずつプレイヤーに迫ってくる）＋弾も打つ
void Bullet::Update()
{
	if (isAlive_) {
		pos_ = pos_ + moveDir_ * speed_ * Scene::DeltaTime();
		SetCharaRect(rectSize_);
		if (IsMyRectHit(RectF({ 0,0 }, { Scene::Width(), Scene::Height() })) == false)
		{
			pos_ = BULLET_INIT_POS;
			DeActivateMe();
		}
	}
	else
		return;
	//画面外に出たら、BULLET_INIT_POSに位置を戻す
	//ここに
	//弾の位置　pos_
	//画面の大きさ　(0,0)-(Scene::Width(), Scene::Height())
	//初期位置：BULLET_INIT_POS
	//画面の外に出たら　DeActivateMe()をよぶ
}

void Bullet::Draw()
{
	if (isAlive_) {
		tex_.resized(renderSize_).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}
