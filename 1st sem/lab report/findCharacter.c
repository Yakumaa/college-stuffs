// 34.WAP to read a word and find specific character entered by user in that word.
#include <stdio.h>
int main(){
    char s[10], searchChar;

    printf("Enter a string: ");
    gets(s);

    printf("Enter a char to search for: ");
    searchChar = getchar();

    for (int i = 0; i < 10; i++)
    {
        if (s[i] == searchChar)
        {
            printf("Found at index %d", i);
        }
        
    }
    return 0;
}

