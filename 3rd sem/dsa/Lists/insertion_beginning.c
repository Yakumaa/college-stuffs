#include<stdio.h>
#include<stdlib.h>
//creating a node
struct node
{
    int info;
    struct node *next;
};
typedef struct node NodeType;


void display(struct node* head)
{
    while (head != NULL)
    {
        printf("%d ", head -> info);
        head = head -> next;
    }
    
};

int main(){
    NodeType *NewNode;
    NodeType *first, *last;
    NodeType *head = NULL;
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


////////////////////////CHATGPT/////////////////////////////
// #include <stdio.h>
// #include <stdlib.h>

// // Define a structure for the nodes of the linked list
// struct Node {
//   int data;
//   struct Node* next;
// };

// // Function to insert a node at the beginning of the linked list
// void insertAtBeginning(struct Node** head_ref, int new_data) {
//   // Allocate memory for the new node
//   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

//   // Set the data of the new node
//   new_node->data = new_data;

//   // Set the next pointer of the new node to point to the current head of the list
//   new_node->next = (*head_ref);

//   // Set the head of the list to point to the new node
//   (*head_ref) = new_node;
// }

// // Function to print the linked list
// void printList(struct Node* head) {
//   // Iterate through the list and print each node's data
//   while (head != NULL) {
//     printf("%d ", head->data);
//     head = head->next;
//   }
//   printf("\n");
// }

// int main() {
//   // Initialize an empty linked list
//   struct Node* head = NULL;

//   // Insert some nodes at the beginning of the list
//   insertAtBeginning(&head, 5);
//   insertAtBeginning(&head, 4);
//   insertAtBeginning(&head, 3);
//   insertAtBeginning(&head, 2);
//   insertAtBeginning(&head, 1);

//   // Print the linked list
//   printList(head);

//   return 0;
// }
