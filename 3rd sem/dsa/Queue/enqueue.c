#include<stdio.h>
#define SIZE 5

int item[SIZE], front = 0, rear = -1;

void enqueue(int value){
    if (rear >= SIZE - 1)
    {
        printf("Queue is full");
    }
    else
        rear = rear + 1;
        item[rear] = value;
        printf("\nInserted -> %d", value);
}

void printQueue(){
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", item[i]);
    }
    
}

int main(){
    enqueue(55);
    enqueue(66);
    enqueue(77);
    printQueue();

    return 0;
}