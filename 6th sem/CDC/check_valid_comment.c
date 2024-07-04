#include <stdio.h>
#include <string.h>

// Function to check if the string is a valid comment
int isValidComment(char *str) {
    int len = strlen(str);
    
    // Check for single-line comment
    if (len >= 2 && str[0] == '/' && str[1] == '/') {
        return 1; // Valid single-line comment
    }
    
    // Check for multi-line comment
    if (len >= 4 && str[0] == '/' && str[1] == '*' && str[len-2] == '*' && str[len-1] == '/') {
        return 1; // Valid multi-line comment
    }
    
    return 0; // Not a valid comment
}

int main() {
    char input[200];
    
    printf("Enter a comment: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character from the end of the string if present
    input[strcspn(input, "\n")] = '\0';
    
    if (isValidComment(input)) {
        printf("'%s' is a valid comment.\n", input);
    } else {
        printf("'%s' is not a valid comment.\n", input);
    }
    
    return 0;
}
