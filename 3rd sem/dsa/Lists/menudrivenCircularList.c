#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *first = NULL, *last = NULL;

int count = 0;

void insertAtFirst(int);
void insertAtLast(int);
void insertAtPosition(int);
void deleteAtFirst();
void deleteAtLast();
void deleteAtPosition();
void countNodes();
void display();

void main(){
    int choice;
    int item;
    char ch;
    
    do
    {
        printf("\n*********MENU***********\n");
        printf(" 1. Insert at first\n 2. Insert at last\n 4. Delete first node\n 5. Delete last node\n 6. Display items\n ");
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
        // case 3:
        //     printf("Enter item to be inserted at specified position: ");
        //     scanf("%d", &item);
        //     insertAtPosition(item);
        //     break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            display();
            break;
        default:
            printf("\nwrong selection!");
        }

    } while (choice < 7);
    
}

void insertAtFirst(int item) {
  // Allocate memory for the new node
  NodeType *NewNode;
  NewNode = (NodeType*)malloc(sizeof(NodeType));

  // Set the info of the new node
  NewNode->info = item;

  if (first == NULL)
  {
    NewNode->next = NULL;
    first = NewNode;
    last = NewNode;
  }
  else{
    // Set the next pointer of the new node to point to the current head of the list
    NewNode->next = first;

    // Set the head of the list to point to the new node
    first = NewNode;

    last ->next = NewNode;
  }
  
}

void insertAtLast(int item) {
  // Allocate memory for the new node
  NodeType *NewNode;
  NewNode = (NodeType*)malloc(sizeof(NodeType));

  // Set the info of the new node
  NewNode->info = item;

  // Check if the linked list is empty
  if (first == NULL) {
    // If the list is empty, set the head of the list to the new node
    first = NewNode;
    last = NewNode;
    NewNode->next = NewNode;
    return;
  }
  else{
    last->next = NewNode;
    last = NewNode;
    NewNode->next = first;
  }
}

// void insertAtPosition(int item) {
//   int position;
//   printf("Enter the position of node at which you want to insert a new node: ");
//   scanf("%d", &position);

//   // Check if the position is valid
//   if (position < 1) {
//     printf("Invalid position\n");
//     return;
//   }

//   // Create a new node
//   NodeType *NewNode; 
//   NewNode = (NodeType*)malloc(sizeof(NodeType));
//   NewNode->info = item;
//   NewNode->next = NULL;

//   // Check if the linked list is empty
//   if (first == NULL) {
//     // If the list is empty, set the head of the list to the new node
//     first = NewNode;
//     last = NewNode;
//   } else {
//     // If the list is not empty, find the node at the specified position
//     NodeType* temp = first;
//     int i = 1;
//     while (i < position && temp->next != NULL) {
//       temp = temp->next;
//       i++;
//     }

//     // Insert the new node after the node at the specified position
//     NewNode->next = temp->next;
//     temp->next = NewNode;
//   }
// }

void deleteAtFirst(){
  NodeType *temp;
  temp = first;
  //check if the linked list is empty
  if (first == NULL)
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
    first = first->next;
    last->next = first;
    free(temp);
  }
  
}

void deleteAtLast(){
  NodeType *temp;
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
    
    temp->next = first;
    free(last);
    last = temp;
    
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