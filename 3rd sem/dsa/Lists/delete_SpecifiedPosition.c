#include<stdio.h>
#include<stdlib.h>

// Define a node of the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to delete the last node of the linked list
void deleteSpecificNode(struct Node** head_ref, int position) {
  // Check if the linked list is empty
  if (*head_ref == NULL) {
    return;
  }

  struct Node* temp = *head_ref;

  //if head need to be removed
  if (position == 0)
  {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  
  for (int i = 0; temp != NULL && i < position -1; i++)
  {
    temp = temp ->next;
  }
  
  // If position is more than number of nodes
  if (temp == NULL || temp->next == NULL)
    return;

  // Node temp->next is the node to be deleted
  // Store pointer to the next of node to be deleted
  struct Node *temp2 = temp->next;
 
  temp->next = temp->next->next;
  // Unlink the node from linked list
  free(temp2);  // Free memory
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
  head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
  head->next->next->next->data = 4;
  head->next->next->next->next = NULL;

  // Print the linked list before deleting the last node
  printf("Linked list before deleting:\n");
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  // Delete the last node of the linked list
  deleteSpecificNode(&head, 2);

  // Print the linked list after deleting the last node
  printf("Linked list after deleting:\n");
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  return 0;
}
