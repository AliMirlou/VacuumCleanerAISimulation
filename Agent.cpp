//
// Created by Ali Mirlou on 10/6/2018.
//

#include "Agent.h"

void Agent::reset() {
	actionsCount = 0;
	batteryRemaining = 10;
}

TrivialAction Agent::act(Percept *percept) {
	if (batteryRemaining == 0)
		return TrivialAction::no_battery;
	TrivialAction action = program(percept);
	++actionsCount;
	--batteryRemaining;
	delete (percept);
	return action;
}
