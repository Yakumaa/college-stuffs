//Write a program to implement Robin Miller algorithm for primality test.

#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n, a, i, j, k, flag;
    cout<<"Enter the number to be tested: ";
    cin>>n;
    cout<<"Enter the number of iterations: ";
    cin>>k;
    for(i=0; i<k; i++)
    {
        a = rand()%(n-2)+2;
        flag = 0;
        if(pow(a, n-1) != 1)
        {
            cout<<n<<" is not a prime number."<<endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        cout<<n<<" is a prime number."<<endl;
    return 0;
}