//
// Created by Ali Mirlou on 10/6/2018.
//

#include "Environment.h"

void Environment::initializeWorld() {
	world = new Square **[length];
	int tempLength = length, tempWidth;
	while (tempLength--) {
		world[tempLength] = new Square *[width];
		tempWidth = width;
		while (tempWidth--) world[tempLength][tempWidth] = new Square(tempLength, tempWidth);
	}
}

Environment::Environment(int length, int width) {
	this->length = length;
	this->width = width;
}

Environment::Environment(long seed) {

}

bool Environment::isValidPosition(int longitude, int latitude) {
	return !(longitude < 0 || longitude >= length || latitude < 0 || latitude >= width);
}

Percept *Environment::percept(Agent *agent) {
	return new Percept(agent->location, agent->location->status);
}
