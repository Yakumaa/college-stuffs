#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* next;
};

typedef struct node NodeType;

void display(struct node* head)
{
    // NodeType* temp = head;
    while (head != NULL)
    {
        printf("%d ->", head -> info);
        head = head -> next;
    }
    printf("NULL\n");
};

void deleteFirstnode(NodeType** head){
    //check if the linked list is empty
    if (head == NULL)
    {
        return;
    }

    NodeType *temp;
    //move head pointer to next node
    temp = *head;
    *head = (*head) ->next;

    //delete the node
    free(temp);
}

void insert(NodeType** head_ref, int new_data){
    NodeType* NewNode = (NodeType*)malloc(sizeof(NodeType));
    NewNode ->info = new_data;
    NewNode ->next = *head_ref;
    *head_ref = NewNode;
}

int main(){
    NodeType* head = NULL;

    insert(&head, 99);
    insert(&head, 88);
    insert(&head, 77);
    insert(&head, 66);
    insert(&head, 55);
    printf("Before Deletion: ");
    display(head);
    deleteFirstnode(&head);
    printf("\nAfter Deletion: ");
    display(head);

    return 0;
}