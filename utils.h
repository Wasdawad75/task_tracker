#include <string>
#include "task.h"

#ifndef UTILS_H
#define UTILS_H

std::string statusToString(task::status s);

task::status stringToStatus(const std::string& s);

#endif