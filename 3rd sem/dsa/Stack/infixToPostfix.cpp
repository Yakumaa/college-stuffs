#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int precedence(char c){
    if (c == '$')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

void inToPost(string s){
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                if (c == '$' && st.top()!= '$')
                {
                    break;
                }
                else{
                    result += st.top();
                    st.pop();
                }
                
            }
            st.push(c);
        }
        
    }
    while (!st.empty()){
        result += st.top();
        st.pop();
    }
    cout << "The postfix expression: " << result << endl;
    
}

int main(){
    string exp;
    char ch;
    do
    {
        cout << "Enter the infix expression: ";
        cin >> exp;
        // exp = "(a+b)*c";
        inToPost(exp);
        cout<< "Do you want to continue? (y/n): ";
        cin >> ch;
    } while (ch != 'n' || ch == 'y');
 
    

    return 0;
}