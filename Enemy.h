#pragma once
#include "GameChara.h"

const int ENEMY_CHR_SIZE{ 48 }; //がぞうさいず
const double ENEMY_RECT_SIZE{ 48 }; //当たり判定用のBBのサイズ
const double ENEMY_MOVE_SPEED{ 2 * ENEMY_CHR_SIZE }; //1s当たりの敵の移動スピード



class Enemy :
    public GameChara
{
public:
	Enemy(Vec2 _pos);
	Enemy();
	void Shot(); //敵が弾を撃つよ
	void FlipMove() { moveDir_ = -moveDir_; } //敵が反対方向に移動
	void MoveDown(); //下に決まった距離下がる
	void Update() override;
	void Draw() override;
};

