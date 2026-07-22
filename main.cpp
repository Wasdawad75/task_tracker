#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "taskDatabase.h"
#include "task.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    taskDatabase db;

    if (argc < 2) {
        std::cout << "Usage: task-cli <command> [args]\n";
        return 1;
    }

    std::string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            std::cout << "Usage: task-cli add <description>\n";
            return 1;
        }
        db.add(argv[2]);
        std::cout << "Task added successfully\n";

    } else if (command == "list") {
        std::vector<task> results;
        if (argc < 3) {
            results = db.listAll();
        } else {
            std::string filter = argv[2];
            if (filter == "done") {
                results = db.listByStatus(task::status::done);
            } else if (filter == "todo") {
                results = db.listByStatus(task::status::notDone);
            } else if (filter == "in-progress") {
                results = db.listByStatus(task::status::inProgress);
            } else {
                std::cout << "Unknown filter: " << filter << "\n";
                return 1;
            }
        }
        for (int i = 0; i < results.size(); ++i) {
            std::cout << results[i].getId() << " | " << results[i].getDescription()
                       << " | " << statusToString(results[i].getStatus()) << "\n";
        }

    } else if (command == "delete") {
        if (argc < 3) {
            std::cout << "Usage: task-cli delete <id>\n";
            return 1;
        }
        try {
            int id = std::stoi(argv[2]);
            if (db.remove(id)) {
                std::cout << "Task deleted successfully\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Invalid id\n";
            return 1;
        }

    } else if (command == "update") {
        if (argc < 4) {
            std::cout << "Usage: task-cli update <id> <new description>\n";
            return 1;
        }
        try {
            int id = std::stoi(argv[2]);
            if (db.update(id, argv[3])) {
                std::cout << "Task updated successfully\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Invalid id\n";
            return 1;
        }

    } else if (command == "mark-done") {
        if (argc < 3) {
            std::cout << "Usage: task-cli mark-done <id>\n";
            return 1;
        }
        try {
            int id = std::stoi(argv[2]);
            if (db.markStatus(id, task::status::done)) {
                std::cout << "Task marked done\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Invalid id\n";
            return 1;
        }

    } else if (command == "mark-in-progress") {
        if (argc < 3) {
            std::cout << "Usage: task-cli mark-in-progress <id>\n";
            return 1;
        }
        try {
            int id = std::stoi(argv[2]);
            if (db.markStatus(id, task::status::inProgress)) {
                std::cout << "Task marked in progress\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Invalid id\n";
            return 1;
        }

    } else {
        std::cout << "Unknown command: " << command << "\n";
        return 1;
    }

    return 0;
}