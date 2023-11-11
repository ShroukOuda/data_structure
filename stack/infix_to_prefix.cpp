#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}
int precedence(char oper)
{
    if (oper == '+' || oper == '-')
    {
    return (1);
    }
    else if (oper == '/' || oper == '*' || oper == '%')
    {
    return (2);
    }
    else if (oper == '^')
    {
    return (3);
    }
    return (0);
}
string InfixToPrefix(string infix)
{
    stack<char> op;
    string prefix;
    for (int i = infix.size() - 1; i >= 0; i--)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
        prefix += ch;
        }
        else if (ch == ')')
        {
        op.push(ch);
        }
        else if (ch == '(')
        {
            while (!op.empty() && op.top() != ')')
            {
                prefix += op.top();
                op.pop();
            }
            op.pop();
        }
        else if (isOperator(ch))
        {
            while(!op.empty() && precedence(op.top()) > precedence(ch))
            {
                prefix += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }
    while (!op.empty())
    {
        prefix += op.top();
        op.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return (prefix);
}
int main()
{
    string infix_exp;
    cout<<"Enter infix Exp: ";
    cin>>infix_exp;
    string prefixexp = InfixToPrefix(infix_exp);
    cout<<"Prefix Exp: "<<prefixexp<<endl;
}