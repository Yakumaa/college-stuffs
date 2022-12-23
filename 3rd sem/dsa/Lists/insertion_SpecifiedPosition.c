#include<stdio.h>
#include<stdlib.h>

// Define a node of the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to insert a new node at a specified position in the linked list
void insertAtPosition(struct Node** head_ref, int data, int position) {
  // Check if the position is valid
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  // Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  // Check if the linked list is empty
  if (*head_ref == NULL) {
    // If the list is empty, set the head of the list to the new node
    *head_ref = new_node;
  } else {
    // If the list is not empty, find the node at the specified position
    struct Node* current = *head_ref;
    int i = 1;
    while (i < position && current->next != NULL) {
      current = current->next;
      i++;
    }

    // Insert the new node after the node at the specified position
    new_node->next = current->next;
    current->next = new_node;
  }
}

int main() {
  // Create a linked list with three nodes
  struct Node* head = NULL;
  head = (struct Node*)malloc(sizeof(struct Node));
  head->data = 1;
  head->next = (struct Node*)malloc(sizeof(struct Node));
  head->next->data = 2;
  head->next->next = (struct Node*)malloc(sizeof(struct Node));
  head->next->next->data = 3;
  head->next->next->next = NULL;

  // Print the linked list before inserting a new node
  printf("Linked list before inserting a new node:\n");
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  // Insert a new node with data 4 at position 2
  insertAtPosition(&head, 4, 2);
  insertAtPosition(&head, 5, 3);
 
  // Print the linked list after inserting a new node
  printf("Linked list after inserting a new node:\n");
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  return 0;
}