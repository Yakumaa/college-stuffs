#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Nodetype;

struct Queue
{
    Nodetype *rear, *front;
};

Nodetype *rear, *front;

void enqueue(struct Queue *q, int item){
    Nodetype *NewNode;
    
    NewNode = (Nodetype*)malloc(sizeof(Nodetype));
    NewNode->info = item;
    NewNode->next = NULL;
    if (q->rear == NULL)
    {
        q->rear = q->front = NewNode;
    }
    else{
        q->rear->next = NewNode;
        q->rear = NewNode;
    }
    
}

void dequeue(struct Queue *q){
    Nodetype *temp;

    if (q->front == NULL)
    {
        printf("Queue is empty");
    }
    else if (q->front->next == NULL)
    {
        temp = q->front;
        q->rear = q->front = NULL;
        printf("Deleted item is %d\n", temp->info);
        free(temp);
    }
    else{
        temp = q->front;
        q->front = q->front->next;
        printf("Deleted item is %d\n", temp->info);
        free(temp);
    }
    
}

void display(struct Queue *q){
    Nodetype *head = q->front;
    while (head != NULL)
    {
        printf("%d-> ", head->info);
        head = head->next;
    }
    printf("NULL\n");
    
}

int main(){
    struct Queue q;
    q.front = q.rear = NULL;
    struct Node* head = NULL;
    enqueue(&q, 99);
    enqueue(&q, 88);
    enqueue(&q, 77);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}