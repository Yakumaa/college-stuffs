#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if the string is a valid identifier
int isValidIdentifier(char *str) {
    // Check if the first character is a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_')) {
        return 0; // Not a valid identifier
    }
    
    // Check the rest of the string
    for (int i = 1; i < strlen(str); i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return 0; // Not a valid identifier
        }
    }
    
    // List of C keywords
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
        "_Bool", "_Complex", "_Imaginary"
    };
    
    // Check if the identifier is a keyword
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 0; // Not a valid identifier
        }
    }
    
    return 1; // Valid identifier
}

int main() {
    char identifier[100];
    
    printf("Enter an identifier: ");
    scanf("%s", identifier);
    
    if (isValidIdentifier(identifier)) {
        printf("'%s' is a valid identifier.\n", identifier);
    } else {
        printf("'%s' is not a valid identifier.\n", identifier);
    }
    
    return 0;
}
