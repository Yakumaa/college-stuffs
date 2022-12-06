// WAP to record the name and age of 5 employee using structure and save them in file named record.txt
#include<stdio.h>
struct employee{
    char name[20];
    int age;
}e;

int main(){
    FILE *f;
    int i;

    f = fopen("record.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        printf("Enter name: ");
        scanf("%s", &e.name);
        printf("Enter age: ");
        scanf("%d", &e.age);
        printf("\n");
        fprintf(f, "%s %d \n", e.name, e.age);
    }
    fclose(f);

    f = fopen("record.txt", "r");
    while((fscanf(f, "%s %d", &e.name, &e.age)) != EOF)
    {
        printf("%s %d\n", e.name, e.age);
    }
    
    fclose(f);
    return 0;
}