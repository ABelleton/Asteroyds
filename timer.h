#pragma once

#include <ctime>

class timer {
private:
	double startTime;
	double timerValue;
	double duration;
	int state; //0 : stopped, 1 : ticking, 2 : finished
public:
	double getTimerValue();
	void resetTimer();
	void updateTimer();
	void startTimer();
	void setDuration(double newDuration);
	double getDuration();

	timer() { startTime = 0; timerValue = 0; state = 0; }
};