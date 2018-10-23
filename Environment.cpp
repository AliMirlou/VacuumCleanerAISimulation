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

Environment::Environment(int length, int width, bool dynamic) {
	this->length = length;
	this->width = width;
	this->dynamic = dynamic;
}

Environment::Environment(unsigned seed, bool dynamic) {
	srand(seed);
	this->length = rand();
	this->width = rand();
	this->dynamic = dynamic;
}

bool Environment::isValidPosition(int longitude, int latitude) {
	return !(longitude < 0 || longitude >= length || latitude < 0 || latitude >= width);
}

Percept *Environment::percept(Agent *agent) {
	return new Percept(agent->location, agent->location->status);
}
