#include "timer.h"

timer::getTimerValue() {
	return time;
}

timer::resetTimer() {
	state = 0;
	timerValue = 50;
}

timer::updateTimer() {
	if (state==1) {
		timerValue = 50 - (time(nullptr) - startTime);
		if (timerValue < 0) {
			timerValue = 0;
			state = 2;
		}
	}
}

timer::startTimer() {
	state = 1;
	startTime = time();
}
