#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    Task(const std::string &desc) : description(desc), isCompleted(false) {}

    std::string getDescription() const {
        return description;
    }
̥
    bool getStatus() const {
        return isCompleted;
    }

    void markCompleted() {
        isCompleted = true;
    }

private:
    std::string description;
    bool isCompleted;
};

class ToDoListManager {
public:
    void addTask(const std::string &desc) {
        tasks.emplace_back(desc);
        std::cout << "Task added: " << desc << "\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].getDescription() 
                      << " [" << (tasks[i].getStatus() ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex == 0 || taskIndex > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }
        tasks[taskIndex - 1].markCompleted();
        std::cout << "Task marked as completed: " << tasks[taskIndex - 1].getDescription() << "\n";
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex == 0 || taskIndex > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }
        std::cout << "Task removed: " << tasks[taskIndex - 1].getDescription() << "\n";
        tasks.erase(tasks.begin() + taskIndex - 1);
    }

private:
    std::vector<Task> tasks;
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    ToDoListManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // to ignore newline character left in the buffer

        switch (choice) {
            case 1: {
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                manager.addTask(description);
                break;
            }
            case 2:
                manager.viewTasks();
                break;
            case 3: {
                std::cout << "Enter task number to mark as completed: ";
                size_t taskNumber;
                std::cin >> taskNumber;
                manager.markTaskCompleted(taskNumber);
                break;
            }
            case 4: {
                std::cout << "Enter task number to remove: ";
                size_t taskNumber;
                std::cin >> taskNumber;
                manager.removeTask(taskNumber);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
