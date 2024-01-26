#include <stdio.h>
#include <stdlib.h>

// Structure to represent a task
struct Task {
    char description[100];
    char deadline[20];
    int priority;
};

// Function to add a new task to the list
void addTask(struct Task *taskList, int *taskCount) {
    printf("Enter task description: ");
    scanf(" %[^\n]", taskList[*taskCount].description);

    printf("Enter task deadline: ");
    scanf(" %[^\n]", taskList[*taskCount].deadline);

    printf("Enter task priority (1-5): ");
    scanf("%d", &taskList[*taskCount].priority);

    (*taskCount)++;
    printf("Task added successfully!\n");
}

// Function to display the list of tasks
void displayTasks(struct Task *taskList, int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nTask List:\n");
    printf("--------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-8s |\n", "Description", "Deadline", "Priority");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < taskCount; i++) {
        printf("| %-20s | %-15s | %-8d |\n", taskList[i].description, taskList[i].deadline, taskList[i].priority);
    }

    printf("--------------------------------------------------------\n");
}

int main() {
    struct Task taskList[100];  // Assuming a maximum of 100 tasks
    int taskCount = 0;
    int choice;

    do {
        printf("\nTask Management System\n");
        printf("1. Add a Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(taskList, &taskCount);
                break;
            case 2:
                displayTasks(taskList, taskCount);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}
