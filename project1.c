#include <stdio.h>
#include <stdlib.h>

// Structure to represent a date
struct Date {
    int jour;
    int mois;
    int annee;
};

// Structure to represent a tache
struct Tache {
    char description[100];
    struct Date deadline;
    int priority;
};

// Function to add a new tache
void AjouteTache(struct Tache tache[], int *tacheCount) {
    printf("Enter tache description: ");
    scanf(" %[^\n]", tache[*tacheCount].description);

    printf("Enter tache deadline (jour): ");
    scanf("%d", &tache[*tacheCount].deadline.jour);
    printf("Enter tache deadline (mois): ");
    scanf("%d", &tache[*tacheCount].deadline.mois);
    printf("Enter tache deadline (annee): ");
    scanf("%d", &tache[*tacheCount].deadline.annee);

    printf("Enter tache priority (1-5): ");
    scanf("%d", &tache[*tacheCount].priority);

    (*tacheCount)++;
    printf("Tache added successfully!\n");
}

// Function to display the list of tache
void AffTache(struct Tache tache[], int tacheCount) {
    if (tacheCount == 0) {
        printf("No tache available.\n");
    } else {
        printf("Tache List:\n");
        for (int i = 0; i < tacheCount; i++) {
            printf("Tache %d:\n", i + 1);
            printf("Description: %s\n", tache[i].description);
            printf("Deadline: %02d/%02d/%04d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("Priority: %d\n\n", tache[i].priority);
        }
    }
}

// Function to modify a tache
void ModiTache(struct Tache tache[], int tacheCount) {
    
        printf("Enter the tache number to modify (1-%d): ", tacheCount);
        int tacheNumber;
        scanf("%d", &tacheNumber);

        
            printf("Enter new tache description: ");
            scanf(" %[^\n]", tache[tacheNumber - 1].description);

            printf("Enter new tache deadline (jour): ");
            scanf("%d", &tache[tacheNumber - 1].deadline.jour);
            printf("Enter new tache deadline (mois): ");
            scanf("%d", &tache[tacheNumber - 1].deadline.mois);
            printf("Enter new tache deadline (annee): ");
            scanf("%d", &tache[tacheNumber - 1].deadline.annee);

            printf("Enter new tache priority (1-5): ");
            scanf("%d", &tache[tacheNumber - 1].priority);

            printf("Tache modified successfully!\n");
}


// Function to delete a tache
void SuppTache(struct Tache tache[], int *tacheCount) {
    
        printf("Enter the tache number to delete (1-%d): ", *tacheCount);
        int tacheNumber;
        scanf("%d", &tacheNumber);

            // Shift taches to fill the gap
            for (int i = tacheNumber - 1; i < *tacheCount - 1; i++) {
                tache[i] = tache[i + 1];
            }

            (*tacheCount)--;
            printf("tache deleted successfully!\n");
}        
// Function To Swap taches 
void Echange(struct Tache *a, struct Tache *b) {
    struct Tache temp = *a;
    *a = *b;
    *b = temp;
}

void OrdCroissant(struct Tache tache[], int tacheCount) {
    for (int i = 0; i < tacheCount - 1; i++) {
        for (int j = 0; j < tacheCount - i - 1; j++) {
            if (tache[j].deadline.annee > tache[j + 1].deadline.annee ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois > tache[j + 1].deadline.mois) ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois == tache[j + 1].deadline.mois &&
                 tache[j].deadline.jour > tache[j + 1].deadline.jour)) {
                Echange(&tache[j], &tache[j + 1]);
            }
        }
    }
}

// Function to sort taches by date in descending order
void OrdDeroissant(struct Tache tache[], int tacheCount) {
    for (int i = 0; i < tacheCount - 1; i++) {
        for (int j = 0; j < tacheCount - i - 1; j++) {
            if (tache[j].deadline.annee < tache[j + 1].deadline.annee ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois < tache[j + 1].deadline.mois) ||
                (tache[j].deadline.annee == tache[j + 1].deadline.annee &&
                 tache[j].deadline.mois == tache[j + 1].deadline.mois &&
                 tache[j].deadline.jour < tache[j + 1].deadline.jour)) {
                Echange(&tache[j], &tache[j + 1]);
            }
        }
    }
}
void FiltrerParPriorite(struct Tache tache[], int tacheCount) {
    int i;
    int priority;

    if (tacheCount > 0) {
        printf("Entrez la priorite (0: Faible, 1: Normale, 2: Importante, 3: TresImportante) : ");
        scanf("%d", &priority);

        printf("taches with priority %d:\n", priority);

        for (i = 0; i < tacheCount; ++i) {
            if (tache[i].priority == priority) {
                printf("tache %d:\n", i + 1);
                printf("Description: %s\n", tache[i].description);
                printf("Date: %02d/%02d/%04d\n", tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);

                switch (tache[i].priority) {
                    case 1:
                        printf("Priority: Faible\n");
                        break;
                    case 2:
                        printf("Priority: Normale\n");
                        break;
                    case 3:
                        printf("Priority: Importante\n");
                        break;
                    case 4:
                        printf("Priority: Tres Importante\n");
                        break;
                    case 5:
                        printf("Priority: Tres Importante\n");
                        break;
                    default:
                        printf("Unknown Priority\n");
                }

                printf("\n");
            }
        }
    } else {
        printf("No taches to display!\n");
    }
}

int main() {
    struct Tache tache[100];  // Assuming a maximum of 100 tache
    int tacheCount = 0;
    int choice;

    do {
        printf("\nTache Manager Menu:\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher Taches\n");
        printf("3. Modifier a Tache\n");
        printf("4. Supprimer a Tache\n");
        printf("5. Taches triees par date (decroissant)\n");
        printf("6. Taches triees par date (croissant)\n");
        printf("7. Filtrer par priorite\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AjouteTache(tache, &tacheCount);
                break;
            case 2:
                AffTache(tache, tacheCount);
                break;
            case 3:
                ModiTache(tache, tacheCount);
                break;
            case 4:
                SuppTache(tache, &tacheCount);
                break;
            case 5:
                OrdCroissant(tache, tacheCount);
                break;
            case 6:
                OrdDeroissant(tache, tacheCount);
                break;
            case 7:
                FiltrerParPriorite(tache, tacheCount);
                break;
            case 8:
                printf("Fermeture du programme. Au revoir !\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    return 0;
}