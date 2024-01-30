#include <stdio.h>
#include <stdlib.h>

// Structure to represent a date
struct Date {
    int jour;
    int mois;
    int annee;
};

// Structure to represent a task
struct Tache {
    char description[100];
    struct Date deadline;
    int priority;
};

// Function to add a new task
void AjouteTache(struct Tache tache[], int *taskCount) {
    printf("Enter task description: ");
    scanf(" %[^\n]", tache[*taskCount].description);

    printf("Enter task deadline (jour): ");
    scanf("%d", &tache[*taskCount].deadline.jour);
    printf("Enter task deadline (mois): ");
    scanf("%d", &tache[*taskCount].deadline.mois);
    printf("Enter task deadline (annee): ");
    scanf("%d", &tache[*taskCount].deadline.annee);

    printf("Enter task priority (1-5): ");
    scanf("%d", &tache[*taskCount].priority);

    (*taskCount)++;
    printf("Tache added successfully!\n");
}

// Function to display the list of tache
void AffTache(struct Tache tache[], int taskCount) {
    if (taskCount == 0) {
        printf("No tache available.\n");
    } else {
        printf("Tache List:\n");
        for (int i = 0; i < taskCount; i++) {
            printf("Tache %d:\n", i + 1);
            printf("Description: %s\n", tache[i].description);
            printf("Deadline: %02d/%02d/%04d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("Priority: %d\n\n", tache[i].priority);
        }
    }
}

// Function to modify a task
void ModiTache(struct Tache tache[], int taskCount) {
    
        printf("Enter the task number to modify (1-%d): ", taskCount);
        int taskNumber;
        scanf("%d", &taskNumber);

        
            printf("Enter new task description: ");
            scanf(" %[^\n]", tache[taskNumber - 1].description);

            printf("Enter new task deadline (jour): ");
            scanf("%d", &tache[taskNumber - 1].deadline.jour);
            printf("Enter new task deadline (mois): ");
            scanf("%d", &tache[taskNumber - 1].deadline.mois);
            printf("Enter new task deadline (annee): ");
            scanf("%d", &tache[taskNumber - 1].deadline.annee);

            printf("Enter new task priority (1-5): ");
            scanf("%d", &tache[taskNumber - 1].priority);

            printf("Tache modified successfully!\n");
}


// Function to delete a task
void SuppTache(struct Tache tache[], int *taskCount) {
    
        printf("Enter the task number to delete (1-%d): ", *taskCount);
        int taskNumber;
        scanf("%d", &taskNumber);

            // Shift tasks to fill the gap
            for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
                tache[i] = tache[i + 1];
            }

            (*taskCount)--;
            printf("Task deleted successfully!\n");
}        
// Function To Swap Tasks 
void swapTaches(struct Tache *a, struct Tache *b) {
    struct Tache temp = *a;
    *a = *b;
    *b = temp;
}

void sortByDateAscending(struct Tache tache[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            if (tache[j].deadline.annee > tache[j + 1].deadline.annee ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois > tache[j + 1].deadline.mois) ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois == tache[j + 1].deadline.mois &&
                 tache[j].deadline.jour > tache[j + 1].deadline.jour)) {
                swapTaches(&tache[j], &tache[j + 1]);
            }
        }
    }
}

// Function to sort tasks by date in descending order
void sortByDateDescending(struct Tache tache[], int taskCount) {
    for (int i = 0; i < taskCount - 1; i++) {
        for (int j = 0; j < taskCount - i - 1; j++) {
            if (tache[j].deadline.annee < tache[j + 1].deadline.annee ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois < tache[j + 1].deadline.mois) ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois == tache[j + 1].deadline.mois &&
                 tache[j].deadline.jour < tache[j + 1].deadline.jour)) {
                swapTaches(&tache[j], &tache[j + 1]);
            }
        }
    }
}


int main() {
    struct Tache tache[100];  // Assuming a maximum of 100 tache
    int taskCount = 0;
    int choice;

    do {
        printf("\nTache Manager Menu:\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher Taches\n");
        printf("3. Modifier a Tache\n");
        printf("4. Supprimer a Tache\n");
        printf("5. Taches triees par date (decroissant)\n");
        printf("6. Taches triees par date (croissant)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AjouteTache(tache, &taskCount);
                break;
            case 2:
                AffTache(tache, taskCount);
                break;
            case 3:
                ModiTache(tache, taskCount);
                break;
            case 4:
                SuppTache(tache, &taskCount);
                break;
            case 5:
                sortByDateAscending(tache, taskCount);
                break;
            case 6:
                sortByDateDescending(tache, taskCount);
                break;
            case 7:
                printf("Fermeture du programme. Au revoir !\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
