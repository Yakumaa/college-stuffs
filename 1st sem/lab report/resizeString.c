//36.WAP to resize the string “Hello World” with new string “Hello Prime college students” using dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
int main(){
    char *ptr;
    int i, oldTextLen, newTextLen;

    char oldText[] = {'H', 'e', 'l', 'l', 'o',' ', 'W', 'o', 'r', 'l', 'd', '\0'};
    char newText[] = {'H', 'e', 'l', 'l', 'o', ' ', 'P', 'r', 'i', 'm', 'e', ' ', 'c', 'o', 'l', 'l', 'e', 'g', 'e', '\0'};

    oldTextLen = sizeof(oldText);
    newTextLen = sizeof(newText);

    ptr = malloc(oldTextLen * sizeof(char));
    for (i = 0; i < oldTextLen; i++)
    {
        ptr[i] = oldText[i];
    }
    printf("Old string: %s\n", ptr);

    ptr = realloc(ptr, newTextLen);
    for ( i = 0; i < newTextLen; i++)
    {
        ptr[i] = newText[i];
    }
    printf("New string: %s\n", ptr);

    free(ptr);
    return 0;
}