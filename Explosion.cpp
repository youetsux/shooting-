#include "stdafx.h"
#include "Explosion.h"

Explosion::Explosion(Vec2 _pos)
	:GameChara(_pos)
{
	speed_ = 0;
	tex_ = TextureAsset(U"BOOOM");
	SetCharaRect(EXPLOSION_RECT_SIZE);
	moveDir_ = { 0,0 };
	isAlive_ = true;
}

void Explosion::Draw()
{
	if (isAlive_)
	{
		tex_.resized(EXPLOSION_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}

void Explosion::Update()
{
}
