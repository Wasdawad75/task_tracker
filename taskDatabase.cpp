#include <iostream>
#include <stdexcept>
#include <vector>
#include "taskDatabase.h"
#include "task.h"
#include "utils.h"
#include <sstream>
#include <fstream>

taskDatabase::taskDatabase() {
    loadFromFile();
}

void taskDatabase::saveToFile() const {
    std::ofstream file("tasks.json");
    file << "[\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        file << "  {\n";
        file << "    \"id\": " << tasks[i].getId() << ",\n";
        file << "    \"description\": \"" << tasks[i].getDescription() << "\",\n";
        file << "    \"status\": \"" << statusToString(tasks[i].getStatus()) << "\",\n";
        file << "    \"createdAt\": \"" << tasks[i].getCreatedAt() << "\",\n";
        file << "    \"updatedAt\": \"" << tasks[i].getUpdatedAt() << "\"\n";
        file << "  }";
        if (i != tasks.size() - 1) file << ",";
        file << "\n";
    }
    file << "]\n";
}

void taskDatabase::loadFromFile() {
    std::ifstream file("tasks.json");
    if (!file.is_open()) {
        // file doesn't exist yet -- create an empty one
        std::ofstream newFile("tasks.json");
        newFile << "[]";
        return;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    tasks.clear();
    nextId = 1;

    size_t pos = 0;
    while ((pos = content.find("\"id\":", pos)) != std::string::npos) {
        pos += 5;
        size_t idEnd = content.find(",", pos);
        int id = std::stoi(content.substr(pos, idEnd - pos));

        size_t descStart = content.find("\"description\":", idEnd) + 15;
        descStart = content.find("\"", descStart) + 1;
        size_t descEnd = content.find("\"", descStart);
        std::string description = content.substr(descStart, descEnd - descStart);

        size_t statusStart = content.find("\"status\":", descEnd) + 9;
        statusStart = content.find("\"", statusStart) + 1;
        size_t statusEnd = content.find("\"", statusStart);
        std::string statusStr = content.substr(statusStart, statusEnd - statusStart);

        size_t createdStart = content.find("\"createdAt\":", statusEnd) + 12;
        createdStart = content.find("\"", createdStart) + 1;
        size_t createdEnd = content.find("\"", createdStart);
        std::string createdAt = content.substr(createdStart, createdEnd - createdStart);

        size_t updatedStart = content.find("\"updatedAt\":", createdEnd) + 12;
        updatedStart = content.find("\"", updatedStart) + 1;
        size_t updatedEnd = content.find("\"", updatedStart);
        std::string updatedAt = content.substr(updatedStart, updatedEnd - updatedStart);

        task t(id, description);
        t.setStatus(stringToStatus(statusStr));
        // note: setStatus/setDescription refresh updatedAt automatically,
        // which overwrites the loaded timestamp -- see note below

        tasks.push_back(t);
        if (id >= nextId) nextId = id + 1;

        pos = updatedEnd;
    }
}
void taskDatabase::add(const std::string& description){
    task new_one(nextId, description);
    tasks.push_back(new_one);
    nextId++;  
    saveToFile();
     
}

bool taskDatabase::update(int id, const std::string& newDescription){
    for (int i = 0; i <tasks.size();i++){
        if (tasks.at(i).getId() == id){
            tasks.at(i).setDescription(newDescription);
            saveToFile();    
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
            saveToFile();
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
            saveToFile();
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





