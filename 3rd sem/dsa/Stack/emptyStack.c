#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5
struct stack
{
    int top;
    int item[STACKSIZE];
};
typedef struct stack st;

void createEmptyStack(st *s){
    s ->top = -1;
}

int isempty(st *s){
    if(s->top == -1){
        printf("stack is empty");
    }
    else{
        printf("stack is not empty");
    }
}

int main(){
    st *s = (st *)malloc(sizeof(st));
    createEmptyStack(s);
    isempty(s);

    return 0;

}