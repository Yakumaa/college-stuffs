#include <stdio.h>
#define SIZE 5

void enqueue(int);
void dequeue();
void display();
void makeEmpty();

int queue[SIZE], front = -1, rear = -1, count = 0;

void main(){
    int item, choice;
    char ch;
    do
    {
        printf("*********MENU***********\n");
        printf(" 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Make Empty\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            enqueue(item);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            makeEmpty();
            break;
        default:
            printf("\nwrong selection!");
        }
        printf("\nDo you want to continue?(y/n): ");
        scanf(" %c", &ch);
        
        if (ch == 'y' && choice == 1)
        {
            count = 1;
        }
        
 
    } while (ch == 'y');

}

void enqueue(int item){
    if (rear == SIZE - 1)
    {
        printf("Queue is full");
    }
    else
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Inserted -> %d", item);

}

void dequeue(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
        printf("Deleted -> %d", queue[front]);
        front++;
    
}

void display(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty");
    }
    else
        printf("\nQueue: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    
}

void makeEmpty(){
    if (front == -1 && rear == -1)
    {
        printf("Queue is already empty");
    }
    else
        front = -1;
        rear = -1;
}
