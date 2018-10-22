//
// Created by Ali Mirlou on 10/6/2018.
//

#ifndef VACUUM_CLEANER_AI_SIMULATOR_H
#define VACUUM_CLEANER_AI_SIMULATOR_H


#include "Environment.h"

extern pair<int, int> parsePosition(string);

class Simulator {
	Environment *environment = nullptr;
	unordered_map<int, Agent *> agents;
	unsigned long long int aliveAgentsCount = 0;
	unordered_map<Square *, bool> dirts;

	/**
	 * Puts an agent on the given coordinates of the world.
	 *
	 * @param[in] agent
	 * @param[in] longitude
	 * @param[in] latitude
	 * @returns True if the position was valid and the agent is positioned successfully, false otherwise.
	 */
	bool putAgent(Agent *agent, int longitude, int latitude);

	/**
	 * Checks if there is at least one agent functioning.
	 *
	 * @returns True if the simulation should stop, false otherwise.
	 */
	bool isDone();

	/**
	 * Orders each agent to act according to the current percept of the environment, all as one time step.
	 */
	void step();

public:
	unordered_map<string, TrivialStatus> *initialState;

	/**
	 * Constructs the simulator with an environment of given length and width.
	 *
	 * @param[in] length
	 * @param[in] width
	 */
	Simulator(int length, int width);

	/**
	 * Adds an agent to simulation by calling the agentFactory.
	 *
	 * @param[in] agentFactory
	 */
	void addAgent(int id, const function<Agent *()> &agentFactory);

	/**
	 * Removes an agent by id.
	 * @param[in] id
	 */
	void removeAgent(int id);

	/**
	 * Initializes a simulation run.
	 */
	void initialize();

	/**
	 * Runs the simulation.
	 *
	 * @param[in] runs Number of times the simulation should initialize and run
	 * @param[in] steps A limit for time steps of each run
	 */
	void run(unsigned int runs = 1, unsigned int steps = 10);
};


#endif //VACUUM_CLEANER_AI_SIMULATOR_H
