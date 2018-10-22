//
// Created by Ali Mirlou on 10/6/2018.
//

#ifndef VACUUM_CLEANER_AI_ENVIRONMENT_H
#define VACUUM_CLEANER_AI_ENVIRONMENT_H


#include "Agent.h"

class Environment {
public:
	int length, width;
	Square ***world;

	/**
	 * Initializes the world.
	 */
	void initializeWorld();

	/**
	* Initialize a clean rectangle environment.
	*
	* @param[in] length
	* @param[in] width
	*/
	Environment(int length, int width);

	/**
	 * Initialize environment randomly with the given seed.
	 *
	 * @param[in] seed
	 */
	explicit Environment(long seed);

	/**
	 * Checks that the coordinates don't fall off the world.
	 *
	 * @param[in] longitude
	 * @param[in] latitude
	 * @returns True if the given coordinates are a valid position in the world.
	 */
	bool isValidPosition(int longitude, int latitude);

	/**
	 * Gives the percept related to the given agent.
	 *
	 * @param[in] agent
	 * @returns A pointer to percept object.
	 */
	Percept *percept(Agent *agent);
};


#endif //VACUUM_CLEANER_AI_ENVIRONMENT_H
