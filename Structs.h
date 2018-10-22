//
// Created by Ali Mirlou on 10/10/2018.
//

#ifndef VACUUM_CLEANER_AI_STRUCTS_H
#define VACUUM_CLEANER_AI_STRUCTS_H


#include "Enums.h"

struct Square {
	int longitude, latitude;
	TrivialStatus status = TrivialStatus::clean;

	Square(int lon, int lat) : longitude {lon}, latitude {lat} {}
	Square(int lon, int lat, TrivialStatus s) : longitude {lon}, latitude {lat}, status {s} {}
};

struct Percept {
	Square *location;
	TrivialStatus status;

	Percept(Square *l, TrivialStatus s) : location {l}, status {s} {}
};


#endif //VACUUM_CLEANER_AI_STRUCTS_H
