#pragma once
#include "GameChara.h"

const SizeF EXPLOSION_CHR_SIZE{ 48, 48 }; //がぞうさいず
const SizeF EXPLOSION_RECT_SIZE{ 48, 48 }; //当たり判定用のBBのサイズ


class Explosion :
    public GameChara
{
public:
	Explosion(Vec2 _pos);
	~Explosion(){}
	void Draw() override;
	void Update() override;
};

