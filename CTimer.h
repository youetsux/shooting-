#pragma once
#include "GameChara.h"

const double DEF_TIMER_TIME{ 1.0 };//デフォルトは１ｓ

class CTimer :
    public GameChara
{
	double CountDownTimer_;  //現在の残り時間
	double TIMER_INIT_TIME_; //初期時間
	bool isTimerRun_;//タイマーが動いているかどうか？
public:
	CTimer()
		:TIMER_INIT_TIME_(DEF_TIMER_TIME),
		 CountDownTimer_(DEF_TIMER_TIME),
		 isTimerRun_(true) {};
	CTimer(double _initTime)
		:TIMER_INIT_TIME_(_initTime),
		 CountDownTimer_(_initTime),
		 isTimerRun_(true) {};
	bool IsTimeOver();//タイマーは０になりましたか？ＹＥＳ？ＮＯ？
	void ResetTimer();//タイマーを初期時間に戻す
	void StartTimer();//タイマーをスタートします
	void StopTimer();//タイマーをストップします
	void Update() override;
	double GetTime() { return(CountDownTimer_); }
};

