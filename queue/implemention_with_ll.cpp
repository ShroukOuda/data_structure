#include <iostream>
#include <stdlib.h>
using namespace std;
class Queue
{
    private:
    struct node
    {
        int data;
        node *next;
    }*front = NULL, *rear = NULL;
    public:
    void enqueue()
    {
        int item;
        node *newnode;
        cout<<"enter data: ";
        cin>>item;
        newnode = new node;
        newnode->data = item;
        if (front == NULL && rear == NULL)
        {
            front = rear = newnode;
            rear->next = 0;
        }
        else
        {
            rear->next = newnode;
            newnode->next = 0;
            rear = newnode;
        }
    }
    void dequeue()
    {
        node *temp = front;
        if (front == NULL && rear == NULL)
        {
            cout<<"QUEUE IS EMPTY\n";
        }
        else if (front == rear)
        {
            front = rear = NULL;
            free(temp);
        }
        else
        {
            front = front->next;
            free(temp);
        }
    }
    void display()
    {
        node *temp = front;
        if (front == NULL && rear == NULL)
        {
            cout<<"QUEUE IS EMPTY\n";
        }
        else
        {
        cout<<"QUEUE IS: \n";
        while (temp != 0)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        }
    }
    void peek()
    {
        if (front == 0 && rear == 0)
        {
            cout<<"QUEUE IS EMPTY\n";
        }
        else
        cout<<front->data<<endl;
    }
    int isempty()
    {
        if (front == 0 && rear == 0)
        return 1;
        return 0;
    }
};
int main()
{
    Queue queue;
    cout<<"1: enqueue\t2: dequeue\t3:display\t4:peek\t5:isempty\t0:exit\n";
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
            case 5: cout<<queue.isempty()<<endl;
            break;
        }
    }
}