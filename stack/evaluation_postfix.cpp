#include <iostream>
#include <stack>
#include <algorithm>
#include <math.h>
using namespace std;
bool Operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int postfix_exp(string postfix)
{
    stack<int> st;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (isalnum(postfix[i]))
        {
            int operand = postfix[i] - 48;
            st.push(operand);
        }
        else if (Operator(postfix[i]))
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch (postfix[i])
            {
                case '+': st.push(op2 + op1);
                break;
                case '-': st.push(op2 - op1);
                break;
                case '*': st.push(op2 * op1);
                break;
                case '/': st.push(op2 / op1);
                break;
                case '%': st.push(op2 % op1);
                break;
                case '^': st.push(pow(op2, op1));
            }
        }
    }
    return (st.top());
}
int main()
{
    string postfix;
    cout<<"Enter postfix exp: ";
    cin>>postfix;
    cout<<"Evaluation is: "<<postfix_exp(postfix)<<endl;
}