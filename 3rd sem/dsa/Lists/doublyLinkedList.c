#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};
typedef struct node NodeType;
NodeType *first = NULL, *last = NULL;

int count = 0;

void insertAtFirst(int);
void insertAtLast(int);
void deleteAtFirst();
void deleteAtLast();
void display();

void main(){
    int choice;
    int item;
    char ch;
    
    do
    {
        printf("\n*********MENU***********\n");
        printf(" 1. Insert at first\n 2. Insert at last\n 3. Delete first node\n 4. Delete last node\n 5. Display items\n ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted at beginning: ");
            scanf("%d", &item);
            insertAtFirst(item);
            break;
        case 2:
            printf("Enter item to be inserted at end: ");
            scanf("%d", &item);
            insertAtLast(item);
            break;
        case 3:
            deleteAtFirst();
            break;
        case 4:
            deleteAtLast();
            break;
        case 5:
            display();
            break;
        default:
            printf("\nwrong selection!");
        }

    } while (choice < 6);
    
}

void insertAtFirst(int item) {
  // Allocate memory for the new node
  NodeType *NewNode;
  NewNode = (NodeType*)malloc(sizeof(NodeType));

  // Set the info of the new node
  NewNode->info = item;

  NewNode->prev = NewNode->next = NULL;

  if (first == NULL)
  {
    first = NewNode;
    last = NewNode;
  }
  else{
    // Set the next pointer of the new node to point to the current head of the list
    NewNode->next = first;

    // Set the head of the list to point to the new node
    first->prev = NewNode;

    first = NewNode;
  }
  
}

void insertAtLast(int item) {
  // Allocate memory for the new node
  NodeType *NewNode;
  NewNode = (NodeType*)malloc(sizeof(NodeType));

  // Set the info of the new node
  NewNode->info = item;

  NewNode->prev = NewNode->next = NULL;

  // Check if the linked list is empty
  if (first == NULL) {
    // If the list is empty, set the head of the list to the new node
    first = NewNode;
    last = NewNode;
  }
  else{
    //might have to traverse
    last->next = NewNode;
    NewNode->prev = last;
    last = NewNode;
  }
}


void deleteAtFirst(){
  NodeType *temp;
  temp = first;
  //check if the linked list is empty
  if (first == NULL)
  {
    printf("Empty list\n");
    return;
  }
  else{
    first = first->next;
    first->prev = NULL;
    free(temp);
  }
  
}

void deleteAtLast(){
  NodeType *temp, *hold;
  temp = first;
  //check if the linked list is empty
  if (last == NULL)
  {
    printf("Empty list\n");
    return;
  }

  else if (first == last)
  {
    first = NULL;
    last = NULL;
    free(temp);
  }
  else{
    while (temp->next != last )
    {
      temp = temp->next;
    }
    
    hold = temp->next;
    temp->next = NULL;
    last = temp;
    free(hold);
    //temp = NULL;
    
  }
  
}

void display(){
  NodeType *temp;
  temp = last;

  if (last == NULL)
  {
    printf("Empty list\n");
    return;
  }
  else{
    temp = first;
    while (temp != last)
    {
      printf("%d ", temp->info);
      temp = temp->next;
    }
    printf("%d", last->info);
    
  }
}