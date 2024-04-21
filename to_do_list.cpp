#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;
public:
    void addTask(string description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
    }

   
    void viewTasks() {
        cout << "TO-DO LIST:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            }
            cout << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task removed successfully!" << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    
    toDoList.addTask("Finish homework");
    toDoList.addTask("Buy groceries");
    toDoList.addTask("Call mom");

   
    toDoList.viewTasks();

   
    toDoList.markTaskAsCompleted(1);

   
    toDoList.removeTask(2);

   
    toDoList.viewTasks();

    return 0;
}