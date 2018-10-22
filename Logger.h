//
// Created by Ali Mirlou on 10/13/2018.
//

#ifndef VACUUM_CLEANER_AI_LOGGER_H
#define VACUUM_CLEANER_AI_LOGGER_H


#include <functional>
#include <string>

using namespace std;

extern string vformat(string zcFormat, ...);

extern function<void(int, string)> Logger(string name_space);


#endif //VACUUM_CLEANER_AI_LOGGER_H
