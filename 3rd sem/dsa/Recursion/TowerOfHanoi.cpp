/*
ALGORITHM
1. Assign 3 pegs; source(A), destination(C), temprorary(B)
2. if n == 1
    Move the single disk from A to C and stop
3. if n > 1
    a) Move the top (n-1) disks from A to B
    b) Move the remaining disks from A to C
    c) Move the (n-1) disks from B to C
*/

#include <iostream>
using namespace std;

void toh(int n, char source, char temp, char destination){
    if (n > 0)
    {
        toh(n-1, source, destination, temp);
        cout << "\nMove disk " << n << " from " << source << " to " << destination;
        toh(n-1, temp, source, destination);
    }
 
}

int main(){
    toh(3, 'S', 'T', 'D');
    return 0;
}