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

void pop(st *s){
    if(s->top == -1){
        printf("stack is empty");
    }
    else{
        printf("Item popped= %d", s->item[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
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
    pop(s);
    printStack(s);

    return 0;

}