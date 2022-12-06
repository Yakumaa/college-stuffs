#include <iostream>
using namespace std;
  
template<class T, class U>
T max(T x, U y){
    return (x >y)?x:y;
}
  
// Driver Code
int main()
{
    cout << max(10, 20);
}