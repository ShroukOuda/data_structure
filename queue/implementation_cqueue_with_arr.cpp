#include <iostream>
using namespace std;
class Cqueue{
    private:
    int cqueue[5];
    int front = -1;
    int rear = -1;
    public:
    void enqueue()
    {
        int x;
        cout<<"enter data: ";
        cin>>x;
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            cqueue[front] = x;
        }
        else if ((rear + 1) % 5 == front)
        {
            cout<<"queue is full\n";
        }
        else
        {
            rear = (rear + 1) % 5;
            cqueue[rear] = x; 
        }
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"queue is empty\n";
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        front = (front + 1) % 5;
    }
    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"queue is empty\n";
        }
        else
        {
            int i = front;
            cout<<"queue is:\n";
            while (i != rear)
            {
                cout<<cqueue[i]<<" ";
                i = (i + 1) % 5;
            }
            cout<<cqueue[i]<<endl;
        }
    }
    void peek()
    {
        if (front == -1 && rear == -1)
        {
            cout<<"queue is empty\n";
        }
        else
        {
            cout<<cqueue[front]<<endl;
        }
    }
    int isempty()
    {
        if (front == -1 && rear == -1)
        return 1;
        else
        return 0;
    }
    int isfull()
    {
        if ((rear + 1) % 5 == front)
        return 1;
        else
        return 0;
    }
};
int main()
{
    Cqueue queue;
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