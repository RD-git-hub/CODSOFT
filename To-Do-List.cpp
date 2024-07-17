#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
struct Task {
    string description;
    bool completed;
    Task(string desc) : description(desc), completed(false) {}
};
void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markTaskCompleted(vector<Task> &tasks, const string &description);
void removeTask(vector<Task> &tasks, const string &description);
int main() {
    vector<Task> tasks;
    char choice;
    cout << "Welcome to the To-Do List Manager!" << endl;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case '1': {
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2':
                viewTasks(tasks);
                break;
            case '3': {
                string taskDescription;
                cout << "Enter task description to mark as completed: ";
                getline(cin, taskDescription);
                markTaskCompleted(tasks, taskDescription);
                break;
            }
            case '4': {
                string taskDescription;
                cout << "Enter task description to remove: ";
                getline(cin, taskDescription);
                removeTask(tasks, taskDescription);
                break;
            }
            case '5':
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number from 1 to 5." << endl;
        }
    } while (choice != '5');

    return 0;
}
void addTask(vector<Task> &tasks, const string &description) {
    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " - Completed";
            } else {
                cout << " - Pending";
            }
            cout << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(), [&description](const Task &task) {
        return task.description == description;
    });

    if (it != tasks.end()) {
        it->completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Task not found." << endl;
    }
}

void removeTask(vector<Task> &tasks, const string &description) {
    auto it = find_if(tasks.begin(), tasks.end(), [&description](const Task &task) {
        return task.description == description;
    });

    if (it != tasks.end()) {
        tasks.erase(it);
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Task not found." << endl;
    }
}
