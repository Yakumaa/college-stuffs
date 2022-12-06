#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 5
struct stack
{
    int top;
    int item[STACKSIZE];
};
typedef struct stack st;

int isfull(st *s){
    if(s->top == STACKSIZE-1){
        printf("stack is full");
    }
    else{
        printf("stack is not full");
    }
}

int main(){
    st *s = (st *)malloc(sizeof(st));
 
    isfull(s);

    return 0;

}