#include "timer.h"

double timer::getTimerValue() {
	return timerValue;
}

void timer::resetTimer() {
	state = 0;
	timerValue = duration;
}

void timer::updateTimer() {
	if (state==1) {
		timerValue = duration - (time(nullptr) - startTime);
		if (timerValue < 0) {
			timerValue = 0;
			state = 2;
		}
	}
}

void timer::startTimer() {
	state = 1;
	startTime = time(nullptr);
}

void timer::setDuration(double newDuration){
	duration=newDuration;
}

double timer::getDuration(){
	return duration;
}


