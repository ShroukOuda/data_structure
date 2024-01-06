#include <iostream>
using namespace std;
class Stack{
    private:
    struct node{
        int data;
        node *link;
    }*top = 0;
    public:
    void push(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        newnode->link = top;
        top = newnode;
    }
    void display()
    {
        node *temp;
        temp = top;
        if (top == 0)
        {
        cout<<"stack is empty\n";
        }
        else
        {
            cout<<"stack is: \n";
            while (temp != 0)
            {
                cout<<temp->data<<" ";
                temp = temp->link;
            }
            cout<<"\n";
        }
    }
    void peek()
    {
        if (top == 0)
        {
            cout<<"stack is empty\n";
        }
        else
        cout<<top->data<<endl;
    }
    void pop()
    {
        node *temp;
        temp = top;
        if (top == 0)
        {
            cout<<"stack is empty\n";
        }
        else
        {
            top = top->link;
            delete(temp);
        }
    }
    int isempty()
    {
        if (top == 0)
        {
        return 1;
        }
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
    stk.peek();
    stk.pop();
    stk.pop();
    stk.display();
    cout<<stk.isempty()<<endl;
}