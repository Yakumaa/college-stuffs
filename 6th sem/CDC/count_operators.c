#include <stdio.h>
#include <string.h>

// Function to check if a character is part of an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '=' || c == '!' || c == '>' || c == '<' || c == '&' ||
            c == '|' || c == '^' || c == '~');
}

// Function to count operators in the input string
int countOperators(char *str) {
    int count = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (isOperator(str[i])) {
            // Check for two-character operators
            if (i + 1 < len) {
                if ((str[i] == '+' && str[i + 1] == '+') || 
                    (str[i] == '-' && str[i + 1] == '-') || 
                    (str[i] == '&' && str[i + 1] == '&') || 
                    (str[i] == '|' && str[i + 1] == '|') || 
                    (str[i] == '=' && str[i + 1] == '=') || 
                    (str[i] == '!' && str[i + 1] == '=') || 
                    (str[i] == '>' && str[i + 1] == '=') || 
                    (str[i] == '<' && str[i + 1] == '=') || 
                    (str[i] == '<' && str[i + 1] == '<') || 
                    (str[i] == '>' && str[i + 1] == '>')) {
                    count++;
                    i++; // Skip the next character
                    continue;
                }
            }
            // Count the single-character operator
            count++;
        }
    }
    return count;
}

int main() {
    char input[200];

    printf("Enter an input string: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the end of the string if present
    input[strcspn(input, "\n")] = '\0';

    int operatorCount = countOperators(input);

    printf("Number of operators in the input string: %d\n", operatorCount);

    return 0;
}
