// 27.Write a recursive function to solve the Tower of Hanoi(TOH)problem.
#include<stdio.h>
void tower(int n, char source, char auxiliary, char destination){
    if (n >0)
    {
        tower(n-1, source, destination, auxiliary);
        printf("Move the disk %d from %c to %c\n", n, source, destination);
        tower(n-1, auxiliary, source, destination);
    }
    
}

int main(){
    tower(3, 'S', 'A', 'D');
    return 0;
}
