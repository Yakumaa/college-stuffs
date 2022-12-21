#include<stdio.h>
#include<stdlib.h>
//creating a node
struct node
{
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *head;

void display(struct node* n)
{
    while (n != NULL)
    {
        printf("%d ", n -> info);
        n = n -> next;
    }
    
};

int main(){
    NodeType *NewNode;
    NodeType *first, *last;
    NewNode = (NodeType*)malloc(sizeof(NodeType));
    first = (NodeType*)malloc(sizeof(NodeType));
    last = (NodeType*)malloc(sizeof(NodeType));
    
    first -> info = 88;
    first -> next = last;
    last ->info = 77;
    last ->next = NULL;
    NewNode -> info = 99;
    NewNode -> next = first;
    
    head = NewNode;
    display(head);
    return 0;
}