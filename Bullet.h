#pragma once
#include "GameChara.h"

const SizeF BULLET_CHR_SIZE{ 8, 17 }; //がぞうさいず
const SizeF BULLET_RECT_SIZE{ 8, 17 }; //当たり判定用のBBのサイズ
const double BULLET_MOVE_SPEED{ 100 }; //プレイヤーの弾の動作スピード
const Vec2 BULLET_INIT_POS{ -BULLET_CHR_SIZE * 2 };


class Bullet :
    public GameChara
{
	SizeF renderSize_;
	SizeF rectSize_;
public:
	Bullet(Texture& _tex);
	void SetRenderSize(SizeF _rendersize); //表示サイズを設定（画像サイズと弾丸の表示サイズが違うとき用）
	void SetBBRectSize(SizeF _rectsize);//バウンディングボックスのサイズを指定（上と一緒）
	void Update() override;
	void Draw() override;

};

