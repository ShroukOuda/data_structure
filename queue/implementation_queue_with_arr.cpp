#include <iostream>
using namespace std;
int queue[100000];
int front = -1;
int rear = -1;
class Queue
{
    public:
    void enqueue()
    {
        int item;
        cout<<"enter item: ";
        cin>>item;
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[rear] = item;
        }
        else if (rear == 100000 - 1)
        {
            cout<<"OVER FLOW\n";
        }
        else
        {
            queue[++rear] = item;
        }
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"UNDER FLOW\n";
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        front++;
    }
    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"QUEUE IS EMPTY\n";
        }
        else
        {
            cout<<"QUEUE: \n";
        for (int i = front; i <= rear; i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
        }
    }
    void peek()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"QUEUE IS EMPTY\n";
        }
        else
        cout<<queue[front]<<endl;
    }
    int isempty()
    {
        if (front == -1 && rear == -1)
        return 1;
        return 0;
    }
    int isfull()
    {
        if (rear == 100000 - 1)
        return 1;
        return 0;
    }
};
int main()
{
    Queue queue;
    cout<<"1: enqueue\t2: dequeue\t3:display\t4:peek\t5:isfull\t6:isempty\t0:exit\n";
    int choice = 1;
    while (choice)
    {
        cout<<"enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: queue.enqueue();
            break;
            case 2: queue.dequeue();
            break;
            case 3: queue.display();
            break;
            case 4: queue.peek();
            break;
            case 5: cout<<queue.isfull()<<endl;
            break;
            case 6: cout<<queue.isempty()<<endl;
            break;
        }
    }
}