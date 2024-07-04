#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define MAX_PRODUCTIONS 10

// Structure to hold the FIRST sets
struct FirstSet {
    char nonTerminal;
    char first[MAX];
};

struct FirstSet firstSets[MAX];
int firstSetCount = 0;

// Helper function to add a symbol to the FIRST set
void addToFirstSet(char nonTerminal, char symbol) {
    for (int i = 0; i < firstSetCount; i++) {
        if (firstSets[i].nonTerminal == nonTerminal) {
            if (!strchr(firstSets[i].first, symbol)) {
                int len = strlen(firstSets[i].first);
                firstSets[i].first[len] = symbol;
                firstSets[i].first[len + 1] = '\0';
            }
            return;
        }
    }
    firstSets[firstSetCount].nonTerminal = nonTerminal;
    firstSets[firstSetCount].first[0] = symbol;
    firstSets[firstSetCount].first[1] = '\0';
    firstSetCount++;
}

// Function to find the FIRST set of a non-terminal
void findFirst(char grammar[][MAX], char nonTerminal, int grammarCount) {
    for (int i = 0; i < grammarCount; i++) {
        if (grammar[i][0] == nonTerminal && grammar[i][1] == '-' && grammar[i][2] == '>') {
            for (int j = 3; j < strlen(grammar[i]); j++) {
                char symbol = grammar[i][j];
                if (symbol == ' ' || symbol == '|') {
                    continue;
                }
                if (islower(symbol) || isdigit(symbol) || symbol == '(' || symbol == ')' || symbol == '+' || symbol == '*' || symbol == '/' || symbol == '-') {
                    addToFirstSet(nonTerminal, symbol);
                    break;
                } else if (isupper(symbol)) {
                    findFirst(grammar, symbol, grammarCount);
                    for (int k = 0; k < firstSetCount; k++) {
                        if (firstSets[k].nonTerminal == symbol) {
                            for (int l = 0; l < strlen(firstSets[k].first); l++) {
                                if (firstSets[k].first[l] != 'ε') {
                                    addToFirstSet(nonTerminal, firstSets[k].first[l]);
                                }
                            }
                            if (!strchr(firstSets[k].first, 'ε')) {
                                break;
                            }
                        }
                    }
                    if (!strchr(firstSets[firstSetCount - 1].first, 'ε')) {
                        break;
                    }
                } else if (symbol == 'ε') {
                    addToFirstSet(nonTerminal, symbol);
                    break;
                }
            }
        }
    }
}

// Function to display the FIRST sets
void displayFirstSets() {
    printf("FIRST sets:\n");
    for (int i = 0; i < firstSetCount; i++) {
        printf("FIRST(%c) = { ", firstSets[i].nonTerminal);
        for (int j = 0; j < strlen(firstSets[i].first); j++) {
            printf("%c ", firstSets[i].first[j]);
        }
        printf("}\n");
    }
}

int main() {
    // Define the grammar
    char grammar[MAX_PRODUCTIONS][MAX] = {
        "E -> TX",
        "X -> +TX",
        "T -> FY",
        "Y -> *FY",
        "F -> (E) | id"
    };
    
    int grammarCount = 5;
    char nonTerminals[] = "EXYTF";
    int n = strlen(nonTerminals);

    // Find FIRST sets for each non-terminal
    for (int i = 0; i < n; i++) {
        findFirst(grammar, nonTerminals[i], grammarCount);
    }

    // Display the FIRST sets
    displayFirstSets();

    return 0;
}
