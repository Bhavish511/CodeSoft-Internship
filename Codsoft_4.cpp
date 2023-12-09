#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 10;

struct Task
{
    string name;
    string status;
};

void displayTasks(const Task tasks[], int taskCount)
{
    if (taskCount == 0) 
	{
        cout << "No tasks in the list." << endl;
    } 
	else 
	{
        cout << "Tasks:" << endl;
        for (int i = 0; i < taskCount; ++i) 
		{
            cout << i + 1 << ". " << tasks[i].name << " - Status: " << tasks[i].status << endl;
        }
    }
}

void addTask(Task tasks[], int& taskCount) 
{
    if (taskCount < MAX_TASKS) 
	{
        Task newTask;
        cout << "Enter the task: ";
        cin.ignore();
        getline(cin, newTask.name);
        newTask.status = "Pending";
        tasks[taskCount] = newTask;
        taskCount++;
        cout << "Task added successfully!" << endl;
    } 
	else 
	{
        cout << "Task list is full. Cannot add more tasks." << endl;
    }
}

void deleteTask(Task tasks[], int& taskCount) 
{
    displayTasks(tasks, taskCount);
    if (taskCount > 0) 
	{
        try 
		{
            cout << "Enter the task number to delete: ";
            int taskNumber;
            cin >> taskNumber;

            if (taskNumber > 0 && taskNumber <= taskCount) 
			{
                cout << "Task '" << tasks[taskNumber - 1].name << "' deleted successfully!" << endl;
                for (int i = taskNumber - 1; i < taskCount - 1; ++i) 
				{
                    tasks[i] = tasks[i + 1];
                }
                taskCount--;
            } 
			else 
			{
                cout << "Invalid task number. Please try again." << endl;
            }
        } 
		catch (...) 
		{
            cout << "Invalid input. Please enter a valid task number." << endl;
        }
    } 
	else 
	{
        cout << "No tasks to delete." << endl;
    }
}

void markTaskCompleted(Task tasks[], int taskCount) 
{
    displayTasks(tasks, taskCount);
    if (taskCount > 0) 
	{
        try 
		{
            cout << "Enter the task number to mark as completed: ";
            int taskNumber;
            cin >> taskNumber;

            if (taskNumber > 0 && taskNumber <= taskCount) 
			{
                tasks[taskNumber - 1].status = "Completed";
                cout << "Task '" << tasks[taskNumber - 1].name << "' marked as completed!" << endl;
            } 
			else 
			{
                cout << "Invalid task number. Please try again." << endl;
            }
        } 
		catch (...) 
		{
            cout << "Invalid input. Please enter a valid task number." << endl;
        }
    } 
	else 
	{
        cout << "No tasks available to mark as completed." << endl;
    }
}

int main() 
{
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;
    while (true) 
	{
        cout << "\n<=========== To-Do List Manager ===========>" << endl;
        cout << "1. View tasks" << endl;
        cout << "2. Add task" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Mark task as completed" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                displayTasks(tasks, taskCount);
                break;
            case 2:
                addTask(tasks, taskCount);
                break;
            case 3:
                deleteTask(tasks, taskCount);
                break;
            case 4:
                markTaskCompleted(tasks, taskCount);
                break;
            case 5:
                cout << "Exiting the to-do list manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }
    return 0;
}
