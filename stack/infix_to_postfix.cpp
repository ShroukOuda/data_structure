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
string InfixToPostfix(string infix)
{
    stack<char> op;
    string postfix;
    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
        postfix += ch;
        }
        else if (ch == '(')
        {
        op.push(ch);
        }
        else if (ch == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else if (isOperator(ch))
        {
            while(!op.empty() && precedence(op.top()) >= precedence(ch))
            {
                if (precedence(op.top()) == precedence(ch))
                {
                    if (op.top() == '^')
                    {
                        break;
                    }
                }
                postfix += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }
    while (!op.empty())
    {
        postfix += op.top();
        op.pop();
    }
    return (postfix);
}
int main()
{
    string infix_exp;
    cout<<"Enter infix Exp: ";
    cin>>infix_exp;
    string postfixexp = InfixToPostfix(infix_exp);
    cout<<"Prefix Exp: "<<postfixexp<<endl;
}