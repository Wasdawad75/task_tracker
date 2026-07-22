#include <vector>
#include <string>
#include "task.h"

#ifndef TASKDATABASE_H
#define TASKDATABASE_H

class taskDatabase {
    std::vector<task> tasks;
    int nextId = 1;

public:

    void add(const std::string& description);
    bool update(int id, const std::string& newDescription);
    bool remove(int id);
    bool markStatus(int id, task::status newStatus);

    std::vector<task> listAll() const;
    std::vector<task> listByStatus(task::status s) const;
    taskDatabase();
    void saveToFile() const;
    void loadFromFile();
};

#endif