#include<stdio.h>
#include<stdlib.h>

struct Task
{
    char description[1];
    struct Date
    {
        int year;
        int month;
        int day;
    };
    int priority;
};


void CreateTask(struct Task task){
    int *size;
    int i;

    for (i = 0; i <= *size; i++){
        printf("Description: \n");
        scanf("%s",&task.description);
        printf("Due Date: dd-mm-year \n");
        scanf("%s",&task.year, &task.month, &task.day);
        printf("Priority: \n");
        scanf("%s",&task.description);
    }
}
void DisplayTask(struct Task task) {
    int *size;
    printf("\nTask Details:\n");
    for(i = 0;i<= *size;i++){
        printf("Description: %s\n", task.description);
    printf("Due Date: %02d-%02d-%04d\n", task.day, task.month, task.year);
    printf("Priority: %d\n", task.priority);
    }
    
}