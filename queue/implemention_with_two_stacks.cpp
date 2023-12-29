#include <iostream>
#include <stack>
using namespace std;
class Queue
{
    private:
    stack <int> st1;
    stack <int> st2;
    public:
    void enqueue()
    {
        int item;
        cout<<"enter item: ";
        cin>>item;
        st1.push(item);
    }
    void dequeue()
    {
        if (!st1.size())
        {
            cout<<"QUEUE IS EMPTY\n";
        }
        else
        {
        while (st1.size())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st2.pop();
        while(st2.size())
        {
            st1.push(st2.top());
            st2.pop();
        }
        }
    }
};
int main()
{
    Queue queue;
    queue.enqueue();
    queue.enqueue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
}