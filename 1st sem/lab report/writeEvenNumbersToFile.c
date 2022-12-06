// 52.WAP to write even numbers between 10 and 50 to a file named EvenNumbers.txt.
#include<stdio.h>
int main(){
    FILE *f;
    int i;
    f = fopen("EvenNumbers.txt", "w");

    for (int i = 10; i <= 50; i++)
    {
        if (i%2 == 0)
        {
            fprintf(f, "%d\t", i);
        }
        
    }

    fclose(f);

    f = fopen("EvenNumbers.txt", "r");
    while((fscanf(f, "%d", &i)) != EOF)
    {
        printf("%d\t", i);
    }
    
    fclose(f);

    
    return 0;
}

