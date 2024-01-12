#include <iostream>
#include <cctype>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int SIZE = 5;

// Function to generate the Playfair key matrix
void generateKeyMatrix(const string &key, char keyMatrix[SIZE][SIZE]) {
    unordered_set<char> uniqueChars;
    string keyWithoutDuplicates = "";

    // Remove duplicate characters from the key
    for (char ch : key) {
        if (isalpha(ch) && uniqueChars.insert(toupper(ch)).second) {
            keyWithoutDuplicates += (toupper(ch) == 'J') ? 'I' : toupper(ch);
        }
    }

    // Fill the key matrix with unique characters from the key
    int k = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (k < keyWithoutDuplicates.length()) {
                keyMatrix[i][j] = keyWithoutDuplicates[k++];
            } else {
                char ch = 'A';
                while (uniqueChars.count(ch) || ch == 'J') {
                    ++ch;
                }
                keyMatrix[i][j] = ch;
                uniqueChars.insert(ch);
            }
        }
    }
}

// Function to find the coordinates of a character in the key matrix
void findCoordinates(char ch, const char keyMatrix[SIZE][SIZE], int &row, int &col) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (keyMatrix[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to perform Playfair Cipher encryption
string encryptPlayfairCipher(const string &plaintext, const char keyMatrix[SIZE][SIZE]) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.length(); i += 2) {
        char firstChar = plaintext[i];
        char secondChar = (i + 1 < plaintext.length()) ? plaintext[i + 1] : 'X';

        // Skip spaces in the plaintext
        if (firstChar == ' ') {
            ciphertext += ' ';
            --i;
            continue;
        }

        int row1, col1, row2, col2;
        findCoordinates(toupper(firstChar), keyMatrix, row1, col1);
        findCoordinates(toupper(secondChar), keyMatrix, row2, col2);

        if (row1 == row2) {
            // Same row, shift right
            ciphertext += keyMatrix[row1][(col1 + 1) % SIZE];
            ciphertext += keyMatrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            // Same column, shift down
            ciphertext += keyMatrix[(row1 + 1) % SIZE][col1];
            ciphertext += keyMatrix[(row2 + 1) % SIZE][col2];
        } else {
            // Different row and column, form a rectangle
            ciphertext += keyMatrix[row1][col2];
            ciphertext += keyMatrix[row2][col1];
        }
    }
    return ciphertext;
}

// Function to remove spaces from the plaintext and perform encryption
string removeSpacesAndEncrypt(const string &plaintext, const char keyMatrix[SIZE][SIZE]) {
    string plaintextWithoutSpaces = "";
    for (char ch : plaintext) {
        if (ch != ' ') {
            plaintextWithoutSpaces += ch;
        }
    }
    return encryptPlayfairCipher(plaintextWithoutSpaces, keyMatrix);
}

// Function to perform Playfair Cipher decryption
string decryptPlayfairCipher(const string &ciphertext, const char keyMatrix[SIZE][SIZE]) {
    string plaintext = "";
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        char firstChar = ciphertext[i];
        char secondChar = (i + 1 < ciphertext.length()) ? ciphertext[i + 1] : 'X';

        // Skip spaces in the ciphertext
        if (firstChar == ' ') {
            plaintext += ' ';
            --i;
            continue;
        }

        int row1, col1, row2, col2;
        findCoordinates(toupper(firstChar), keyMatrix, row1, col1);
        findCoordinates(toupper(secondChar), keyMatrix, row2, col2);

        if (row1 == row2) {
            // Same row, shift left
            plaintext += keyMatrix[row1][(col1 - 1 + SIZE) % SIZE];
            plaintext += keyMatrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            // Same column, shift up
            plaintext += keyMatrix[(row1 - 1 + SIZE) % SIZE][col1];
            plaintext += keyMatrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            // Different row and column, form a rectangle
            plaintext += keyMatrix[row1][col2];
            plaintext += keyMatrix[row2][col1];
        }
    }
    return plaintext;
}

int main() {
    char keyMatrix[SIZE][SIZE];
    string key, input;

    // Get key from the user
    cout << "Enter the key for the Playfair Cipher: ";
    getline(cin, key);

    // Generate the key matrix
    generateKeyMatrix(key, keyMatrix);

    // Display the key matrix
    cout << "Key Matrix:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Get input (plaintext or ciphertext) from the user
    cout << "Enter the text: ";
    getline(cin, input);

    // Perform encryption with spaces removed
    string ciphertext = removeSpacesAndEncrypt(input, keyMatrix);

    // Display the encrypted text
    cout << "Encrypted Text: " << ciphertext << endl;

    // Perform decryption
    string decryptedText = decryptPlayfairCipher(ciphertext, keyMatrix);

    // Display the decrypted text
    cout << "Decrypted Text: " << decryptedText << endl;

    cout << "-------------------------------------------------------" << endl;
    cout << "Lab N0.: 2" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll N0.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0; // Exit successfully
}


// // C++ program to implement Playfair Cipher

// #include <bits/stdc++.h>
// using namespace std;
// #define SIZE 30

// // Function to convert the string to lowercase
// void toLowerCase(char plain[], int ps)
// {
// 	int i;
// 	for (i = 0; i < ps; i++) {
// 		if (plain[i] > 64 && plain[i] < 91)
// 			plain[i] += 32;
// 	}
// }

// // Function to remove all spaces in a string
// int removeSpaces(char* plain, int ps)
// {
// 	int i, count = 0;
// 	for (i = 0; i < ps; i++)
// 		if (plain[i] != ' ')
// 			plain[count++] = plain[i];
// 	plain[count] = '\0';
// 	return count;
// }

// // Function to generate the 5x5 key square
// void generateKeyTable(char key[], int ks, char keyT[5][5])
// {
// 	int i, j, k, flag = 0;

// 	// a 26 character hashmap
// 	// to store count of the alphabet
// 	int dicty[26] = { 0 };
// 	for (i = 0; i < ks; i++) {
// 		if (key[i] != 'j')
// 			dicty[key[i] - 97] = 2;
// 	}

// 	dicty['j' - 97] = 1;

// 	i = 0;
// 	j = 0;

// 	for (k = 0; k < ks; k++) {
// 		if (dicty[key[k] - 97] == 2) {
// 			dicty[key[k] - 97] -= 1;
// 			keyT[i][j] = key[k];
// 			j++;
// 			if (j == 5) {
// 				i++;
// 				j = 0;
// 			}
// 		}
// 	}

// 	for (k = 0; k < 26; k++) {
// 		if (dicty[k] == 0) {
// 			keyT[i][j] = (char)(k + 97);
// 			j++;
// 			if (j == 5) {
// 				i++;
// 				j = 0;
// 			}
// 		}
// 	}
// }

// // Function to search for the characters of a digraph
// // in the key square and return their position
// void search(char keyT[5][5], char a, char b, int arr[])
// {
// 	int i, j;

// 	if (a == 'j')
// 		a = 'i';
// 	else if (b == 'j')
// 		b = 'i';

// 	for (i = 0; i < 5; i++) {

// 		for (j = 0; j < 5; j++) {

// 			if (keyT[i][j] == a) {
// 				arr[0] = i;
// 				arr[1] = j;
// 			}
// 			else if (keyT[i][j] == b) {
// 				arr[2] = i;
// 				arr[3] = j;
// 			}
// 		}
// 	}
// }

// // Function to find the modulus with 5
// int mod5(int a) { return (a % 5); }

// // Function to make the plain text length to be even
// int prepare(char str[], int ptrs)
// {
// 	if (ptrs % 2 != 0) {
// 		str[ptrs++] = 'z';
// 		str[ptrs] = '\0';
// 	}
// 	return ptrs;
// }

// // Function for performing the encryption
// void encrypt(char str[], char keyT[5][5], int ps)
// {
// 	int i, a[4];

// 	for (i = 0; i < ps; i += 2) {

// 		search(keyT, str[i], str[i + 1], a);

// 		if (a[0] == a[2]) {
// 			str[i] = keyT[a[0]][mod5(a[1] + 1)];
// 			str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
// 		}
// 		else if (a[1] == a[3]) {
// 			str[i] = keyT[mod5(a[0] + 1)][a[1]];
// 			str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
// 		}
// 		else {
// 			str[i] = keyT[a[0]][a[3]];
// 			str[i + 1] = keyT[a[2]][a[1]];
// 		}
// 	}
// }

// // Function to encrypt using Playfair Cipher
// void encryptByPlayfairCipher(char str[], char key[])
// {
// 	char ps, ks, keyT[5][5];

// 	// Key
// 	ks = strlen(key);
// 	ks = removeSpaces(key, ks);
// 	toLowerCase(key, ks);

// 	// Plaintext
// 	ps = strlen(str);
// 	toLowerCase(str, ps);
// 	ps = removeSpaces(str, ps);

// 	ps = prepare(str, ps);

// 	generateKeyTable(key, ks, keyT);

// 	encrypt(str, keyT, ps);
// }

// // Driver code
// int main()
// {
// 	char str[SIZE], key[SIZE];

// 	// Key to be encrypted
// 	strcpy(key, "keyword");
// 	cout << "Key text: " << key << "\n";

// 	// Plaintext to be encrypted
// 	strcpy(str, "meet me tonight");
// 	cout << "Plain text: " << str << "\n";

// 	// encrypt using Playfair Cipher
// 	encryptByPlayfairCipher(str, key);

// 	cout << "Cipher text: " << str << "\n";

// 	return 0;
// }

// // This code is contributed by aditya942003patil
