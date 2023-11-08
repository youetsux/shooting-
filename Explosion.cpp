#include "stdafx.h"
#include "Explosion.h"

const SizeF IMG_SIZE{ 48,48 };

Explosion::Explosion(Vec2 _pos)
	:GameChara(_pos),timer_(ANIME_INTERVAL)
{
	speed_ = 0;
	tex_ = TextureAsset(U"BOOOM");
	SetCharaRect(EXPLOSION_RECT_SIZE);
	moveDir_ = { 0,0 };
	isAlive_ = true;
	frames_ = {
		{ 0, 0,IMG_SIZE},
		{48, 0,IMG_SIZE},
		{96, 0,IMG_SIZE},
		{ 0,48,IMG_SIZE},
		{48,48,IMG_SIZE},
		{96,48,IMG_SIZE},
		{ 0,96,IMG_SIZE},
		{48,96,IMG_SIZE},
		{96,96,IMG_SIZE},
	};
}

void Explosion::Draw()
{
	if (isAlive_)
	{
		tex_(frames_[frameNum_]).resized(EXPLOSION_CHR_SIZE).drawAt(pos_);
		rect_.drawFrame(1, 1, Palette::Red);
	}
}

void Explosion::Update()
{
	if (timer_.IsTimeOver()) {
		frameNum_ = ++frameNum_;
		if (frameNum_ >= MAX_FRAME_NUM)
		{
			DeActivateMe();
		}
		timer_.ResetTimer();

	}
	else
		timer_.Update();
	
}
