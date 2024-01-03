// /*
//  * Cpp program to find Primitive roots of a given number
//  */

// #include <iostream>
// #include <vector>
// // #include "./returnName.h"

// using namespace std;

// // Function to calculate (a^b) % m using modular exponentiation
// int power(int a, int b, int m)
// {
//     int result = 1;
//     a = a % m;
//     while (b > 0)
//     {
//         if (b % 2 == 1)
//         {
//             result = (result * a) % m;
//         }
//         a = (a * a) % m;
//         b = b / 2;
//     }
//     return result;
// }

// // Function to find the greatest common divisor (GCD) of two numbers
// int gcd(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }
//     return gcd(b, a % b);
// }

// // Function to find primitive roots of a given number n
// vector<int> findPrimitiveRoots(int n)
// {
//     vector<int> primitiveRoots;

//     for (int r = 2; r < n; r++)
//     {
//         if (gcd(r, n) == 1)
//         {
//             bool isPrimitiveRoot = true;
//             for (int i = 1; i <= n - 2; i++)
//             {
//                 if (power(r, i, n) == 1)
//                 {
//                     isPrimitiveRoot = false;
//                     break;
//                 }
//             }
//             if (isPrimitiveRoot)
//             {
//                 primitiveRoots.push_back(r);
//             }
//         }
//     }

//     return primitiveRoots;
// }

// int main()
// {
//     // generateHeader("Program to find Primitive roots of a given number");
//     int n;
//     do{
//         cout << "Enter a positive integer: ";
//         cin >> n;
//         vector<int> primitiveRoots = findPrimitiveRoots(n);

//         if (primitiveRoots.empty())
//         {
//             cout << "No primitive roots found for " << n << endl;
//         }
//         else
//         {
//             cout << "Primitive roots of " << n << " are: ";
//             for (int root : primitiveRoots)
//             {
//                 cout << root << " ";
//             }
//             cout << endl;
//         }

//         cout << "Do you want to continue? (y/n): ";
//         char ch;
//         cin >> ch;
//         if (ch == 'n' || ch == 'N')
//             break;

//     } while (true);
//     return 0;
// }

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate the power of a number modulo p
int power(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }

    return result;
}

// Function to check if a number is a primitive root modulo p
bool isPrimitiveRoot(int a, int p) {
    vector<bool> visited(p, false);

    for (int i = 1; i < p; ++i) {
        int value = power(a, i, p);

        // Check if the value is in the range [1, p-1] and is distinct
        if (value < 1 || value >= p || visited[value]) {
            return false;
        }

        visited[value] = true;
    }

    return true;
}

// Function to find primitive roots of a given prime number p
vector<int> findPrimitiveRoots(int p) {
    vector<int> primitiveRoots;

    for (int a = 2; a < p; ++a) {
        if (isPrimitiveRoot(a, p)) {
            primitiveRoots.push_back(a);
        }
    }

    return primitiveRoots;
}

int main() {
    int p;

    // Get input from the user
    cout << "Enter a prime number to find its primitive roots: ";
    cin >> p;

    // Check if the input is a prime number
    if (p < 2) {
        cout << "Invalid input. Please enter a prime number greater than 1." << endl;
        return 1;
    }

    // Find and display primitive roots of the given prime number
    vector<int> roots = findPrimitiveRoots(p);

    if (roots.empty()) {
        cout << "No primitive roots found for " << p << "." << endl;
    } else {
        cout << "Primitive Roots of " << p << " are: ";
        for (int root : roots) {
            cout << root << " ";
        }
        cout << endl;
    }

    return 0;
}
