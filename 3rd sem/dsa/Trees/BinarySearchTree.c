#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* newNode(int key) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() {
    int choice, key;
    struct node* root = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. In-Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key found\n");
                } else {
                    printf("Key not found\n");
                }
                break;
            case 4:
                printf("In-Order Traversal: ");
                inOrder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}