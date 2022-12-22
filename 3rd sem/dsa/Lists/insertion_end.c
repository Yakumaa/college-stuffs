// #include<stdio.h>
// #include<stdlib.h>
// //creating a node
// struct node
// {
//     int info;
//     struct node *next;
// };
// typedef struct node NodeType;


// void display(struct node* head)
// {
//     NodeType *temp = head;
//     while (temp != NULL)
//     {
//         printf("%d-> ", temp -> info);
//         temp = temp -> next;
//     }
//     printf("NULL\n");
    
// };

// int main(){
//     NodeType *NewNode;
//     NodeType *first, *second;
//     NodeType *head = NULL;
//     NodeType *temp;

//     NewNode = (NodeType*)malloc(sizeof(NodeType));
//     first = (NodeType*)malloc(sizeof(NodeType));
//     second = (NodeType*)malloc(sizeof(NodeType));
    
//     first -> info = 88;
//     first -> next = second;
//     second ->info = 77;
//     second ->next = NewNode;
//     NewNode -> info = 99;
//     NewNode -> next = NULL;

//     //MAKE HEAD NOT NULL//
//     // Check if the linked list is empty
//     if (head == NULL)
//     {
//       head = NewNode;
//     }
//     else{
//       // If the list is not empty, find the temp node
//       while (temp ->next != NULL)
//       {
//         temp = temp ->next;
//       }
      
//       // Set the next pointer of the temp node to the new node
//       temp->next = NewNode;
//     }
//     display(head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes of the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
  // Allocate memory for the new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // Set the data of the new node
  new_node->data = new_data;

  // Set the next pointer of the new node to NULL
  new_node->next = NULL;

  // Check if the linked list is empty
  if (*head_ref == NULL) {
    // If the list is empty, set the head of the list to the new node
    *head_ref = new_node;
    return;
  }

  // If the list is not empty, find the last node
  struct Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }

  // Set the next pointer of the last node to the new node
  last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
  // Iterate through the list and print each node's data
  while (head != NULL) {
    printf("%d-> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int main() {
  // Initialize an empty linked list
  struct Node* head = NULL;

  // Insert some nodes at the end of the list
  insertAtEnd(&head, 1);
  insertAtEnd(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 5);

  // Print the linked list
  printList(head);

  return 0;
}