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
        printf("*********MENU***********\n");
        printf(" 1. Insert at first\n 2. Insert at last\n 3. Insert at given position\n \
                4. Delete first node\n 5. Delete last node\n 6. Delete specified node\n \
                7. count nodes\n 8. Display items\n 9. exit\n");
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
            printf("Enter item to be inserted at specified position: ");
            scanf("%d", &item);
            insertAtPosition(item);
            break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            countNodes();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(1);
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
  }
  
}

void insertAtEnd(int item) {
  // Allocate memory for the new node
  NodeType *NewNode;
  NewNode = (NodeType*)malloc(sizeof(NodeType));

  // Set the info of the new node
  NewNode->info = item;

  // Set the next pointer of the new node to NULL
  NewNode->next = NULL;

  // Check if the linked list is empty
  if (first == NULL) {
    // If the list is empty, set the head of the list to the new node
    first = NewNode;
    last = NewNode;
    return;
  }
  else{
    last->next = NewNode;
    last = NewNode;
  }
}

void insertAtPosition(int item) {
  int position;
  printf("Enter the position of node at which you want to insert a new node: ");
  scanf("%d", &position);

  // Check if the position is valid
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  // Create a new node
  NodeType *NewNode; 
  NewNode = (NodeType*)malloc(sizeof(NodeType));
  NewNode->info = item;
  NewNode->next = NULL;

  // Check if the linked list is empty
  if (first == NULL) {
    // If the list is empty, set the head of the list to the new node
    first = NewNode;
    last = NewNode;
  } else {
    // If the list is not empty, find the node at the specified position
    NodeType* temp = first;
    int i = 1;
    while (i < position && temp->next != NULL) {
      temp = temp->next;
      i++;
    }

    // Insert the new node after the node at the specified position
    NewNode->next = temp->next;
    temp->next = NewNode;
  }
}

void deleteAtFirst(){
  NodeType **head;
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