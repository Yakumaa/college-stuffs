//37.WAP to create a student structure that has name, roll, marks, dob (where dob is another structure having membersyear, month and day),phone as members. Read member values from user and display the details of 5 students entered by user.
#include<stdio.h>
struct dob{
    int year;
    int month;
    int day;
}db;

struct student{
    char name[20];
    int roll;
    float marks;
    struct dob;
    int phone;
}std;

int main(){
    struct student std[5];
    struct dob db[5];
    int i;

    for ( i = 0; i <= 4; i++)
    {
        printf("Enter student %d details \n", i+1);
        printf("Enter your name: ");
        scanf("%s", &std[i].name);
        printf("Enter your roll: ");
        scanf("%d", &std[i].roll);
        printf("Enter your marks: ");
        scanf("%f", &std[i].marks);
        printf("Enter your birth year: ");
        scanf("%d", &db[i].year);
        printf("Enter your birth month: ");
        scanf("%d", &db[i].month);
        printf("Enter your birth day: ");
        scanf("%d", &db[i].day);
        printf("Enter your phone: ");
        scanf("%d", &std[i].phone);
    }
        puts("");
    for ( i = 0; i <= 4; i++)
    {
        printf("details of student %d are: \n", i+1);
        printf("Name: %s\n", std[i].name);
        printf("Roll: %d\n", std[i].roll);
        printf("Marks %.1f\n", std[i].marks);
        printf("DOB: %d-%d-%d\n", db[i].year, db[i].month, db[i].day);
        printf("Phone: %d\n", std[i].phone);

    }
    return 0;
}