#pragma once
#include "GameChara.h"
#include <vector>
#include "CTimer.h"
using std::vector;

const SizeF EXPLOSION_CHR_SIZE{ 48, 48 }; //がぞうさいず
const SizeF EXPLOSION_RECT_SIZE{ 48, 48 }; //当たり判定用のBBのサイズ
const int MAX_FRAME_NUM{ 9 };//アニメのコマ数
const double ANIME_INTERVAL{ 1 / 15.0 };//アニメーションの間隔

class Explosion :
    public GameChara
{
	vector<RectF> frames_;
	CTimer timer_;
	int frameNum_;
public:
	Explosion(Vec2 _pos);
	~Explosion(){}
	void Draw() override;
	void Update() override;
};

