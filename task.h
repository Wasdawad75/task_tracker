#include <string>

#ifndef TASK_H
#define TASK_H

class task {
    int id;
    std::string description;

public:
    enum class status { notDone, inProgress, done };

    // constructor from an id and description (used when adding a new task)
    task(int id_, const std::string& description_);

    // getters
    int getId() const;
    std::string getDescription() const;
    status getStatus() const;
    std::string getCreatedAt() const;
    std::string getUpdatedAt() const;

    // setters
    void setDescription(const std::string& description_);
    void setStatus(status s);

private:
    status current_status;
    std::string createdAt;
    std::string updatedAt;

    std::string currentTimestamp() const;
};

#endif