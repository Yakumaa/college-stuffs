#include<stdio.h>
#define SIZE 5

int item[SIZE], front, rear;

void createEmptyQueue(){
    front = -1;
    rear = -1;
}

void isEmpty(){
    if (front == -1 || rear == -1)
    {
        printf("Queue is empty!");
    }
    else
        printf("Queue is not empty");
    
}

int main(){
    createEmptyQueue();
    isEmpty();
    return 0;
}