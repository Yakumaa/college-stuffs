#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Function to perform Extended Euclidean Algorithm
int extendedEuclidean(int a, int b, vector<int> &x, vector<int> &y, vector<int> &q, vector<int> &r) {
    // Base case
    if (b == 0) {
        x.push_back(1);
        y.push_back(0);
        q.push_back(0);
        r.push_back(a);
        return a;
    }

    // Recursive call
    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x, y, q, r);

    // Update x and y using results of recursive call
    x.push_back(y.back());
    y.push_back(x.back() - (a / b) * y.back());
    q.push_back(a / b);
    r.push_back(a % b);

    return gcd;
}

// Function to display results of iterations in tabular format
void displayResults(int a, int b, const vector<int> &q, const vector<int> &r, const vector<int> &x, const vector<int> &y) {
    cout << setw(4) << "Step" << setw(4) << "q" << setw(4) << "r" << setw(4) << "x" << setw(4) << "y" << endl;
    cout << "-------------------------" << endl;

    for (size_t i = 0; i < q.size(); ++i) {
        cout << setw(4) << i + 1;
        cout << setw(4) << q[i];
        cout << setw(4) << r[i];
        cout << setw(4) << x[i];
        cout << setw(4) << y[i];
        cout << endl;
    }

    cout << "-------------------------" << endl;
    cout << "GCD(" << a << ", " << b << ") = " << r.back() << endl;
    cout << "Coefficients x and y: x = " << x.back() << ", y = " << y.back() << endl;
}

int main() {
    int a, b;
    cout << "Enter the first number (a): ";
    cin >> a;

    cout << "Enter the second number (b): ";
    cin >> b;

    vector<int> q, r, x, y;

    // Run the Extended Euclidean Algorithm
    int gcd = extendedEuclidean(a, b, x, y, q, r);

    // Display the results in a tabular format
    displayResults(a, b, q, r, x, y);

    cout << "-------------------------------------------------------" << endl;
    cout << "Lab No.: 8" <<endl;
    cout << "Name: Shirish Maharjan" <<endl;
    cout << "Roll No.: 20-00036-5 (Section: 'A')" <<endl;
    cout << "-------------------------------------------------------" << endl;

    return 0; // Exit successfully
}
