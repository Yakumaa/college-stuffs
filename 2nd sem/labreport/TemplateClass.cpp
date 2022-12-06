#include <iostream>
using namespace std;
  
template<class T>
class temp{
private:
    T a, b;
public:
    temp(T x, T y){
        a = x;
        b = y;
    }
    T max(){
    return (a >b)?a:b;
}
};

  
// Driver Code
int main()
{
    temp<int> obj(10 ,20);
    cout << obj.max();
}