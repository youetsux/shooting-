#include "stdafx.h"
#include "CTimer.h"

bool CTimer::IsTimeOver()
{
	return(CountDownTimer_ <= 0);
}

void CTimer::ResetTimer()
{
	CountDownTimer_ = TIMER_INIT_TIME_;
	StartTimer();
}

void CTimer::StartTimer()
{
	isTimerRun_ = true;
}

void CTimer::StopTimer()
{
	isTimerRun_ = false;
}

void CTimer::Update()
{
	if (isTimerRun_)
		CountDownTimer_ = CountDownTimer_ - Scene::DeltaTime();
}
