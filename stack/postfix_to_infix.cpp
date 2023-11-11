#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
bool Operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
string postfix_to_infix(string postfix)
{
    string infix;
    stack <string> st;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (isalnum(postfix[i]))
        {
            st.push(string(1, postfix[i]));
        }
        else if (Operator(postfix[i]))
        {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();
            infix = "(" + operand2 + postfix[i] + operand1 + ")";
            st.push(infix);
        }
    }
    return (st.top());
}
int main()
{
    string postfix;
    cout<<"Enter postfix exp: ";
    cin>>postfix;
    cout<<"Infix exp: "<<postfix_to_infix(postfix)<<endl;
}