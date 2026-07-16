#include <iostream>
#include <stdexcept>
#include <vector>
#include <ctime>
#include "task.h"

task::task(int id_, const std::string& description_){
    id = id_;
    description = description_;
    createdAt = currentTimestamp();
    updatedAt = currentTimestamp();
}

int task::getId() const {
    return id;
}

std::string task::getDescription() const {
    return description;
}

task::status task::getStatus() const {
    return current_status;
}

std::string task::getCreatedAt() const {
    return createdAt;
}

std::string task::getUpdatedAt() const {
    return updatedAt;
}

void task::setDescription(const std::string& description_) {
    description = description_;
    updatedAt = currentTimestamp();
}

void task::setStatus(const task::status s) {
    current_status = s;
    updatedAt = currentTimestamp();
}

std::string task::currentTimestamp() const {
    std::time_t p = time(nullptr);
    tm* current = localtime(&p);
    char buf[100];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", current);
    return buf;
}