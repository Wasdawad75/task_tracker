#include <iostream>
#include <stdexcept>
#include <vector>
#include "task.h"

#ifndef TASKDATABASE_H
#define TASKDATABASE_H

class taskDatabase {
    int number;
    std::vector<task> tasks;


    public:
    taskDatabase();

    ~taskDatabase();

    taskDatabase(const taskDatabase& other);

    taskDatabase& operator=(const taskDatabase& other);

    //add a task

    //update a task

    //delete a task

    //list ALL tasks

    //List ALL DONE tasks

    //List ALL NOT DONE tasks

    //List ALL PROGRESS tasks

    taskDatabase& add(task& tasks);

    void update(taskDatabase& database);

    taskDatabase& delete_(task& tasks);

    void list_all(taskDatabase& database);

    void list_not_done(taskDatabase& database);

    void list_wip(taskDatabase& database);




};

#endif