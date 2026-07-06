//define the task class
#include <iostream>
#include <stdexcept>
#include <string>

#ifndef TASK_H
#define TASK_H

class task {
    double id;
    std::string description;
    enum status {};
    struct createdAt;
    struct updatedAt;

public:
    //default constructor
    task();

    //destructor
    ~task();

    //copy constructor
    task(const task& other);

    //via assignment
    task& operator=(const task& other);

    //add a task

    //update a task

    //delete a task

    //list ALL tasks

    //List ALL DONE tasks

    //List ALL NOT DONE tasks

    //List ALL PROGRESS tasks
};

#endif
