#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Nodetype;
Nodetype *top;

void push(int item){
    Nodetype *NewNode;
    
    NewNode = (Nodetype*)malloc(sizeof(Nodetype));
    NewNode->info = item;
    NewNode->next = top;

    top = NewNode;
    
}

void pop(){
    Nodetype *temp = top;

    if (top == NULL)
    {
        printf("stack is empty");
    }
    else{
        top = top->next;
        printf("Deleted item is %d\n", temp->info);
        free(temp);
    }
    
}

void display(){
    Nodetype *head = top;
    while (head != NULL)
    {
        printf("%d-> ", head->info);
        head = head->next;
    }
    printf("NULL\n");
    
}

int main(){
    top = NULL;
    struct Node* head = NULL;
    push(99);
    push(88);
    push(77);
    display();
    pop();
    display();
    return 0;
}