#include "stdafx.h"
#include "Player.h"

const SizeF SHOT_IMG_SIZE{ 8.0,17.0 }; //画像の大きさ
const SizeF SHOT_RENDER_SIZE{ 8.0,17.0 }; //描画の大きさ



Player::Player()
	:GameChara()
{
	Vec2 chrMargin{ 0, Scene::Height() / 2 - PLAYER_CHR_SIZE };
	pos_ = Scene::Center() + chrMargin;
	speed_ = PLAYER_MOVE_SPEED;
	tex_ = TextureAsset(U"PLAYER");
	SetCharaRect(SizeF{ PLAYER_RECT_SIZE,PLAYER_RECT_SIZE });
	moveDir_ = { 0, 0 };
	isAlive_ = true;
}

void Player::Initialize()
{
	Texture pGunTex = TextureAsset(U"SHOT1");
	gun_ = new Bullet(pGunTex); //Bulletクラスのインスタンスgun_をせいせい　画像はSHOT1
	gun_->SetRenderSize(SHOT_RENDER_SIZE);
	gun_->SetBBRectSize(SHOT_RENDER_SIZE);
	gun_->DeActivateMe();
	gun_->SetPosition(BULLET_INIT_POS); //画面の外の邪魔にならない場所に弾をおいておく
	gun_->SetCharaRect(SHOT_RENDER_SIZE);
	gun_->SetMoveDir({ 0, -1 });


}

direction Player::GetDirection()
{
	if ((KeyUp | KeyW).pressed())
	{
		return UP;
	}
	else if ((KeyLeft | KeyA).pressed())
	{
		return LEFT;
	}
	else if ((KeyDown | KeyS).pressed())
	{
		return DOWN;
	}
	else if ((KeyRight | KeyD).pressed())
	{
		return RIGHT;
	}
	else
		return NONE;
}

void Player::Update()
{   //寿命短い変数は名前も少し適当でいいよ


	direction d = GetDirection();
	switch (d)
	{
	case LEFT:
		moveDir_ = { -1.0, 0 };
		break;
	case RIGHT:
		moveDir_ = { 1.0, 0 };
		break;
	default:
		moveDir_ = { 0.0, 0.0 };
		break;
	}
	if (KeyB.down())//キーボードのBキーで弾丸発射
	{   //isAlive:true  弾が発射されている状態（弾が動いている）
		//isAlive:false 弾が待機状態（発射準備）
		if (gun_->isActive() == false) {
			gun_->SetPosition(pos_);
			gun_->ActivateMe();
		}
	}
	gun_->Update();
	pos_ = pos_ + speed_ * Scene::DeltaTime() * moveDir_;
	SetCharaRect(SizeF{ PLAYER_RECT_SIZE,PLAYER_RECT_SIZE });


}

void Player::Draw()
{
	if (gun_->isActive())
	{
		gun_->Draw();
	}
	if (isAlive_) {
		tex_.resized(PLAYER_CHR_SIZE).drawAt(pos_);
		//rect_.drawFrame(1, 1, Palette::Red);
	}
}

