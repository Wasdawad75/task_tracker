#include "utils.h"

std::string statusToString(task::status s) {
    switch (s) {
        case task::status::notDone:
            return "todo";
        case task::status::inProgress:
            return "in-progress";
        case task::status::done:
            return "done";
    }
    return ""; // fallback, shouldn't be reached
}

task::status stringToStatus(const std::string& s) {
    if (s == "todo") return task::status::notDone;
    if (s == "in-progress") return task::status::inProgress;
    if (s == "done") return task::status::done;
    return task::status::notDone;
}