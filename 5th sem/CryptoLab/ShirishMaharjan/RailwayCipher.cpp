// C++ program to illustrate Rail Fence Cipher
// Encryption and Decryption
#include <iostream>
using namespace std;

// function to encrypt a message
string encryptRailFence(string text, int key)
{
	// create the matrix to cipher plain text
	// key = rows , length(text) = columns
	char rail[key][(text.length())];

	// filling the rail matrix to distinguish filled
	// spaces from blank ones
	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	// to find the direction
	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++)
	{
		// check the direction of flow
		// reverse the direction if we've just
		// filled the top or bottom rail
		if (row == 0 || row == key-1)
			dir_down = !dir_down;

		// fill the corresponding alphabet
		rail[row][col++] = text[i];

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	//now we can construct the cipher using the rail matrix
	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);

	return result;
}

// This function receives cipher-text and key
// and returns the original text after decryption
string decryptRailFence(string cipher, int key)
{
	// create the matrix to cipher plain text
	// key = rows , length(text) = columns
	char rail[key][cipher.length()];

	// filling the rail matrix to distinguish filled
	// spaces from blank ones
	for (int i=0; i < key; i++)
		for (int j=0; j < cipher.length(); j++)
			rail[i][j] = '\n';

	// to find the direction
	bool dir_down;

	int row = 0, col = 0;

	// mark the places with '*'
	for (int i=0; i < cipher.length(); i++)
	{
		// check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// place the marker
		rail[row][col++] = '*';

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	// now we can construct the fill the rail matrix
	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];


	// now read the matrix in zig-zag manner to construct
	// the resultant text
	string result;

	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		// check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// place the marker
		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		// find the next row using direction flag
		dir_down?row++: row--;
	}
	return result;
}

//driver program to check the above functions
int main()
{
    string input;
    int rails;

    // Get input (plaintext or ciphertext) from the user
    cout << "Enter the text: ";
    getline(cin, input);

    // Get the number of rails from the user
    cout << "Enter the number of rails: ";
    cin >> rails;

    // Perform encryption
    string ciphertext = encryptRailFence(input, rails);

    // Display the encrypted text
    cout << "Encrypted Text: " << ciphertext << endl;

    // Perform decryption
    string decryptedText = decryptRailFence(ciphertext, rails);

    // Display the decrypted text
    cout << "Decrypted Text: " << decryptedText << endl;

    cout << "-------------------------------------------------------" << endl;
    cout << "Lab N0.: 3" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll N0.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0; // Exit successfully
}
