#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 256

struct Task {
    char description[MAX_LENGTH];
};

void addTask() {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char task[MAX_LENGTH];
    printf("Enter task description: ");
    getchar(); // Clear input buffer
    fgets(task, MAX_LENGTH, stdin);
    task[strcspn(task, "\n")] = 0; // Remove newline

    fprintf(file, "%s\n", task);
    fclose(file);
    printf("Task added successfully!\n");
}

void viewTasks() {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("No tasks found yet. Create one!\n");
        return;
    }

    char task[MAX_LENGTH];
    int index = 1;
    printf("\n--- Your Tasks ---\n");
    while (fgets(task, MAX_LENGTH, file) != NULL) {
        task[strcspn(task, "\n")] = 0;
        printf("%d. %s\n", index++, task);
    }
    fclose(file);
}

void clearTasks() {
    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Error resetting tasks!\n");
        return;
    }
    fclose(file);
    printf("All tasks cleared!\n");
}

int main() {
    int choice;
    do {
        printf("\n=== Taskify-CLI ===\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Clear All Tasks\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                clearTasks();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}