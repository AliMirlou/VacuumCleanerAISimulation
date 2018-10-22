//
// Created by Ali Mirlou on 10/6/2018.
//

#ifndef VACUUM_CLEANER_AI_ACTIONS_H
#define VACUUM_CLEANER_AI_ACTIONS_H


enum class TrivialAction {
	right,
	left,
	suck,
	no_op,
	no_battery
};

enum class TrivialStatus {
	clean,
	dirty
};


#endif //VACUUM_CLEANER_AI_ACTIONS_H
