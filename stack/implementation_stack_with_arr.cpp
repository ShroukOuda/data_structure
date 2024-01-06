#include <iostream>
using namespace std;
class Stack{
    private:
    int size = 50000;
    int stk[50000];
    int top = -1;
    public:
    void push(int x)
    {
        if (top == size - 1)
        {
            cout<<"OVER FLOW\n";
        }
        else
        {
            top++;
            stk[top] = x;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout<<"UNDER FLOW\n";
        }
        else
        top--;
    }
    void peek()
    {
        if (top == -1)
        cout<<"stack is empty\n";
        else
        cout<<stk[top]<<endl;
    }
    void display()
    {
        if (top == -1)
        cout<<"stack is empty\n";
        else
        {
            cout<<"stack is: \n";
            for (int i = top; i >= 0; i--)
            cout<<stk[i]<<" ";
            cout<<endl;
        }
    }
    int isempty()
    {
        if (top == -1)
        return 1;
        else
        return 0;
    }
    int isfull()
    {
        if (top == size - 1)
        return 1;
        else 
        return 0;
    }
};
int main()
{
    Stack stk;
    stk.push(6);
    stk.push(4);
    stk.push(9);
    stk.display();
    stk.pop();
    stk.display();
    cout<<stk.isempty()<<endl;
    cout<<stk.isfull()<<endl;
    stk.peek();
    stk.pop();
    stk.pop();
    stk.display();
    cout<<stk.isempty()<<endl;
}