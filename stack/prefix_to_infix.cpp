#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
bool Operator(char c)
{
    return (c == '+' || c == '*' || c == '/' || c == '-' || c == '%' || c == '^');
}
string prefix_to_infix(string prefix)
{
    reverse(prefix.begin(), prefix.end());
    string infix;
    stack<string> st;
    for (int i = 0; i < prefix.size(); i++)
    {
        if (isalnum(prefix[i]))
        {
            st.push(string(1, prefix[i]));
        }
        else if (Operator(prefix[i]))
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            infix = "(" + operand1 + prefix[i] + operand2 + ")";
            st.push(infix); 
        }
    }
    return (st.top());
}
int main()
{
    string prefix;
    cout<<"enter prefix exp: ";
    cin>>prefix;
    cout<<"infix exp: "<< prefix_to_infix(prefix)<<endl;
}