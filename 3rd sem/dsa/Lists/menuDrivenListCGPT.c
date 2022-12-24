#include<stdio.h>
#include<stdlib.h>

// Define a node of the linked list
struct Node {
  int data;
  struct Node* next;
};

// void insertAtBeginning(int);
// void insertAtEnd(int);
// void insertAtPosition(int);
// void deleteFirst();
// void deleteLast();
// void deleteAtPosition();
// //void countNodes();
// void printList();


void main() {
  // Create an empty linked list
  struct Node* head = NULL;

  // Run the menu-driven program
  int choice = 0;
  while (choice != 9) {
    printf("Menu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at position\n");
    printf("4. Delete first\n");
    printf("5. Delete last\n");
    printf("6. Delete at position\n");
    printf("7. Print list\n");
    printf("9. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int data, position;
    switch (choice) {
      case 1: // Insert at beginning
        printf("Enter the data: ");
        scanf("%d", &data);
        insertAtBeginning(&head, data);
        break;
      case 2: // Insert at end
        printf("Enter the data: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);
        break;
      case 3: // Insert at position
        printf("Enter the data: ");
        scanf("%d", &data);
        printf("Enter the position: ");
        scanf("%d", &position);
        insertAtPosition(&head, data, position);
        break;
      case 4: // Delete first
        deleteFirst(&head);
        break;
      case 5: // Delete last
        deleteLast(&head);
        break;
      case 6: // Delete at position
        printf("Enter the position: ");
        scanf("%d", &position);
        deleteAtPosition(&head, position);
        break;
      case 7: // Print list
        printList(head);
        break;
      case 9: // Quit
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int data) {
  // Create a new node
  struct Node* new_node = malloc(sizeof(struct Node));

  // Set the data field of the new node
  new_node->data = data;

  // Set the next field of the new node to the current head of the list
  new_node->next = *head_ref;

  // Set the head of the list to the new node
  *head_ref = new_node;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int data) {
  // Create a new node
  struct Node* new_node = malloc(sizeof(struct Node));

  // Set the data field of the new node
  new_node->data = data;

  // Set the next field of the new node to NULL
  new_node->next = NULL;

  // Check if the linked list is empty
  if (*head_ref == NULL) {
    // If the list is empty, set the head of the list to the new node
    *head_ref = new_node;
  } else {
    // If the list is not empty, find the last node
    struct Node* current = *head_ref;
    while (current->next != NULL) {
      current = current->next;
    }

    // Insert the new node after the last node
    current->next = new_node;
    }
}
// Function to insert a new node at a specified position in the linked list
void insertAtPosition(struct Node** head_ref, int data, int position) {
  // Check if the position is valid
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  // Create a new node
  struct Node* new_node = malloc(sizeof(struct Node));
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

// Function to delete the first node of the linked list
void deleteFirst(struct Node** head_ref) {
  // Check if the linked list is empty
  if (*head_ref == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  // Save a pointer to the first node
  struct Node* temp = *head_ref;

  // Set the head of the list to the second node
  *head_ref = (*head_ref)->next;

  // Free the memory used by the first node
  free(temp);
}

// Function to delete the last node of the linked list
void deleteLast(struct Node** head_ref) {
  // Check if the linked list is empty
  if (*head_ref == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  // Check if the linked list has only one node
  if ((*head_ref)->next == NULL) {
    // If the list has only one node, set the head of the list to NULL
    *head_ref = NULL;
    return;
  }

  // Find the second to last node
  struct Node* current = *head_ref;
  while (current->next->next != NULL) {
    current = current->next;
  }

  // Free the memory used by the last node
  free(current->next);

  // Set the next field of the second to last node to NULL
  current->next = NULL;
}

// Function to delete a node at a specified position in the linked list
void deleteAtPosition(struct Node** head_ref, int position) {
  // Check if the position is valid
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  // Check if the linked list is empty
  if (*head_ref == NULL) {
    printf("Linked list is empty\n");
    return;
  }

  // Check if the position is the first node
  if (position == 1) {
    // If the position is the first node, delete the first node
    deleteFirst(head_ref);
    return;
  }

  // Find the node at the specified position
  struct Node* current = *head_ref;
  int i = 1;
  while(i < position - 1 && current->next != NULL) {
    current = current->next;
    i++;
  }

  // Check if the position is beyond the end of the list
  if (current->next == NULL) {
    printf("Invalid position\n");
    return;
  }

  // Save a pointer to the node to be deleted
  struct Node* temp = current->next;

  // Set the next field of the node before the node to be deleted to the node after the node to be deleted
  current->next = temp->next;

  // Free the memory used by the node to be deleted
  free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}



