#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
bool Operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int prefix_exp(string prefix)
{
    stack<int> st;
    reverse(prefix.begin(), prefix.end());
    for (int i = 0; i < prefix.size(); i++)
    {
        if (isalnum(prefix[i]))
        {
            int operand = prefix[i] - 48;
            st.push(operand);
        }
        else if (Operator(prefix[i]))
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (prefix[i])
            {
                case '+': st.push(op1 + op2);
                break;
                case '-': st.push(op1 - op2);
                break;
                case '*': st.push(op1 * op2);
                break;
                case '/': st.push(op1 / op2);
                break;
                case '%': st.push(op1 % op2);
                break;
                case '^': st.push(pow(op1, op2));
            }
        }
    }
    return (st.top());
}
int main()
{
    string prefix;
    cout<<"Enter postfix exp: ";
    cin>>prefix;
    cout<<"Evaluation is: "<<prefix_exp(prefix)<<endl;
}