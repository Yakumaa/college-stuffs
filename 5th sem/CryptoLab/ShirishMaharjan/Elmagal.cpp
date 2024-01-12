//WAP to implement Elgamal Cryptographic System

#include <iostream>
#include <cmath>

using namespace std;

int power(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    int p, g, x, k, y1, y2, m;
    cout << "Enter a prime number (p): ";
    cin >> p;

    cout << "Enter a primitive root (g) modulo " << p << ": ";
    cin >> g;

    cout << "Enter Alice's private key (x): ";
    cin >> x;

    cout << "Enter Bob's private key (k): ";
    cin >> k;

    cout << "Enter the message to be encrypted (m): ";
    cin >> m;

    y1 = power(g, k, p);
    y2 = (power(y1, x, p) * m) % p;

    cout << "Encrypted message: (" << y1 << ", " << y2 << ")" << endl;

    int decryptedMessage = (power(y1, p - 1 - x, p) * y2) % p;
    cout << "Decrypted message: " << decryptedMessage << endl;

    cout << "-------------------------------------------------------" << endl;
    cout << "Lab No.: 18" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll No.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;
}