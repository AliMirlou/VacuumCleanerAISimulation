#include <utility>

//
// Created by Ali Mirlou on 10/6/2018.
//

#ifndef VACUUM_CLEANER_AI_AGENT_H
#define VACUUM_CLEANER_AI_AGENT_H


#include <functional>
#include "Structs.h"

using namespace std;

class Agent {
public:
	int id;
	unsigned int actionsCount = 0;
	unsigned int batteryRemaining = 10;
	Square *location;
	function<TrivialAction(Percept *)> program;

	Agent(int i, function<TrivialAction(Percept *)> p) : id{i}, program{p} {}

	/**
	 * Resets the agent to it's initial state.
	 */
	void reset();

	/**
	 * Runs it's program with the given percept, if battery is remaining.
	 * deletes the percept object at the end.
	 *
	 * @param[in] percept
	 * @returns An action returned by program
	 */
	TrivialAction act(Percept *percept);
};


#endif //VACUUM_CLEANER_AI_AGENT_H
