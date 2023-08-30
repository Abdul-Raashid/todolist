#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(string desc) {
        tasks.push_back(Task(desc));
        cout << "Task added: " << desc << endl;
    }

    void viewTasks() {
        cout << "Todo List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
        }
    }

    void markComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as complete: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\nTodo List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Complete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string desc;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, desc);
                todoList.addTask(desc);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as complete: ";
                cin >> index;
                todoList.markComplete(index - 1);
                break;
            }
            case 4:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
