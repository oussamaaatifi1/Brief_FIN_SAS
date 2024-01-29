#include<stdio.h>
#include<stdlib.h>

struct Tache {
    char description[10];
    char deadline[10];
    int priorite;
};

void ajoutetache(struct Tache *tache,int *tachcount ){
    printf("entrez new description est:\n");
    scanf("%[^\n]",tache[*tachcount].description);

    printf("entrez new deadline est:\n");
    scanf("%[^\n]",tache[*tachcount].deadline);

    printf("entrez new priority (1-5) est:\n");
    scanf("%d",&tache[*tachcount].priorite);

    (*tachcount)++;
    printf("le tache a ajouter avec succes\n");
}

void AfficheList(struct Tache *tache,int tachcount){
    int i;
    printf("\ntache list est : ");
    printf("---------------------------------------------------------------\n");
    printf("| %-20s | %-15s | %-9s |\n","description", "deadline", "priorite" );
    printf("---------------------------------------------------------------\n");
    for (i = 0 ; i < tachcount ; i++){
        printf("| %-20s | %-15s | %-9d |\n" ,tache[i].description,tache[i].deadline,tache[i].priorite);
    }
    printf("---------------------------------------------------------------\n");
}

void ModifierList(struct Tache *tache,int tachcount){
    int tacheIndex;
    printf("veuillez entre le nombre de tache pour modifier est (1-%d) :",tachcount);
    scanf("%d",&tacheIndex);

    tacheIndex--;
    printf("entrez new description est:");
    scanf("%[^\n]",tache[tachcount].description);
    printf("entrez new deadline est:");
    scanf("%[^\n]",tache[tachcount].deadline);
    printf("entrez new priority (1-5) est:");
    scanf("%d",&tache[tachcount].priorite);

    printf("Tache modifie avec succes!\n");
}
void SupprimerTach(struct Tache tache[], int *tacheCount) {
    int tacheIndex;

    printf("Enter tache number to delete: ");
    scanf("%d", &tacheIndex);
    getchar(); // consume newline character

    for (int i = tacheIndex - 1; i < *tacheCount - 1; i++) {
        tache[i] = tache[i + 1];
    }

    (*tacheCount)--;

    printf("tache deleted successfully!\n");
}

int main () {
    struct Tache tache[5];
    int tachcount = 0;
    int choice;
    

    do {
        printf("\n veuillez chose : \n");
        printf("1- ajouter taches\n");
        printf("2- afficher Listes\n");
        printf("3- Modifier taches\n");
        printf("3- Supprimer taches\n");
        printf("4- Sortie\n");
        printf("\nveuillez entrez le choice :");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            ajoutetache(tache,&tachcount);
            break;
        case 2:
            AfficheList(tache,tachcount);
            break;
        case 3:
            AfficheList(tache,tachcount);
            break;
        case 4:
            SupprimerTach(tache,&tachcount);
            break;
        case 5:
            printf("exite le programme\n");
            break;
        default:
        printf("error\n");
            break;
        }
    }while (choice != 5);

}
