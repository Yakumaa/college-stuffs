#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void push(int);
void pop();
void display();
void makeEmpty();
void peek();

int stack[SIZE], top = -1, count = 0;

void main(){
    int item, choice;
    char ch;
    do
    {
        printf("*********MENU***********\n");
        printf(" 1. Push\n 2. Pop\n 3. Display\n 4. Make Empty\n 5. Peek\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            makeEmpty();
            break;
        case 5:
            peek();
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

void push(int item){
    if (top == SIZE-1)
    {
        printf("Stack is Full");
    }
    else{
        top++;
        stack[top] = item;
        printf("Insertion Successfull\n");
    }
}

void pop(){
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else{
        printf("Deleted: %d", stack[top]);
        top--;
    }
}

void display(){
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else{
        printf("Stack elements are: \n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
        
    }
    
}

void makeEmpty(){
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else{
        top = -1;
        printf("Stack is made empty\n");
    }
    
}

void peek(){
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else{
        printf("The item at the top is %d", stack[top]);
    }
}