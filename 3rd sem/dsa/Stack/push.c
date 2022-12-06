#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5

int count = 0;

struct stack
{
    int top;
    int item[STACKSIZE];
};
typedef struct stack st;

void createEmptyStack(st *s) {
  s->top = -1;
}

void push(st *s, int newitem){
    if(s->top == STACKSIZE-1){
        printf("stack is full");
    }
    else{
        s -> top++;
        s -> item[s->top] = newitem;
    }
    count++;
}

// Print elements of stack
void printStack(st *s) {
  printf("Stack: ");
  for (int i = 0; i < count; i++) {
    printf("%d ", s->item[i]);
  }
  printf("\n");
}


int main(){
    st *s = (st *)malloc(sizeof(st));
 
    createEmptyStack(s);
    push(s, 2);
    push(s, 3);
    printStack(s);

    return 0;

}