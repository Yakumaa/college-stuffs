#include<stdio.h>
#define SIZE 5

int item[SIZE], front = -1, rear = -1;

void dequeue(){
    if (front == -1)
    {
        printf("Queue is empty");
    }
    else
        
        printf("\nDeleted -> %d", item[front]);
        front++;
}

void printQueue(){
    printf("\nQueue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", item[i]);
    }
    
}

int main(){
    //int item[5] = {99, 88, 77, 66, 55};
    dequeue();
    printQueue();

    return 0;
}