#include <iostream>
#include <stdexcept>
#include <vector>
#include "taskDatabase.h"
#include "task.h"


void taskDatabase::add(const std::string& description){
    task new_one(nextId, description);
    tasks.push_back(new_one);
    nextId++;   
}

bool taskDatabase::update(int id, const std::string& newDescription){
    for (int i = 0; i <tasks.size();i++){
        if (tasks.at(i).getId() == id){
            tasks.at(i).setDescription(newDescription);
            return true;
        }

    }
    std::cout<<"Could not find this id. Try Again";
    return false;
}

bool taskDatabase::remove(int id) {
    for (int i = 0; i <tasks.size();i++){
        if (tasks.at(i).getId() == id){
            tasks.erase(tasks.begin()+i,tasks.begin()+i+1);
            return true;
        }

    }
    std::cout<<"Could not find this id. Try Again";
    return false;
}

bool taskDatabase::markStatus(int id, task::status newStatus){
    for (int i = 0; i <tasks.size();i++){
        if (tasks.at(i).getId() == id){
            tasks.at(i).setStatus(newStatus);
            return true;
        }

    }
    std::cout<<"Could not find this id. Try Again";
    return false;
}

std::vector<task> taskDatabase::listAll() const {
    return tasks;
}

std::vector<task> taskDatabase::listByStatus(task::status s) const {
    std::vector<task> sorted;
    for(int i = 0; i < tasks.size();++i){
        if (tasks.at(i).getStatus() == s){
            sorted.push_back(tasks.at(i));
    }
}
    return sorted;
}





