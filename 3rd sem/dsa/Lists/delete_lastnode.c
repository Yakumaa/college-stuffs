#include<stdio.h>
#include<stdlib.h>

// Define a node of the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to delete the last node of the linked list
void deleteLastNode(struct Node** head_ref) {
  // Check if the linked list is empty
  if (*head_ref == NULL) {
    return;
  }

  // Check if the linked list has only one node
  if ((*head_ref)->next == NULL) {
    // Free the memory allocated for the node
    free(*head_ref);

    // Set the head of the list to NULL
    *head_ref = NULL;
    return;
  }

  // Iterate through the list to find the second-to-last node
  struct Node* second_to_last = *head_ref;
  while (second_to_last->next->next != NULL) {
    second_to_last = second_to_last->next;
  }

  // Set the next pointer of the second-to-last node to NULL
  second_to_last->next = NULL;

  // Free the memory allocated for the last node
  free(second_to_last->next);
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
  printf("Linked list before deleting the last node:\n");
  struct Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  // Delete the last node of the linked list
  deleteLastNode(&head);

  // Print the linked list after deleting the last node
  printf("Linked list after deleting the last node:\n");
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  return 0;
}
