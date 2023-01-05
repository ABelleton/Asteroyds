#pragma once

import <ctime>

class timer {
private:
	double startTime;
	double timerValue;
	int state; //0 : stopped, 1 : ticking, 2 : finished
public:
	double getTimerValue();
	void resetTimer();
	void updateTimer();
	void startTimer();

	timer() { startTime = 0; timerValue = 0; state = 0; }
};