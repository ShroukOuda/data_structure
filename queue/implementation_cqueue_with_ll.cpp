#include <iostream>
using namespace std;
class Cqueue{
    private:
    struct node{
        int data;
        node *next;
    }*front = NULL, *rear = NULL;
    public:
    void enqueue()
    {
        int x;
        cout<<"enter data: ";
        cin>>x;
        node *newnode;
        newnode = new node;
        newnode->data = x;
        newnode->next = 0;
       if (front == NULL && rear == NULL)
       {
        front = rear = newnode;
        newnode->next = front;
       }
      else
      {
        rear->next = newnode;
        newnode->next = front;
        rear = newnode;
      }
    }
    void dequeue()
    {
        node *temp;
        temp = front;
        if (front == NULL && rear == NULL)
        {
            cout<<"queue is empty\n";
        }
        else if (front == rear)
        {
            front = rear = NULL;
            delete(temp);
        }
        else
        {
            front = front->next;
            rear->next = front;
            delete(temp);
        }
    }
    void display()
    {
        node *temp;
        temp = front;
        if (front == NULL && rear == NULL)
        {
            cout<<"queue is empty\n";
        }
        else
        {
            cout<<"queue is:\n";
            while (temp->next != front)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<temp->data<<endl;
        }
    }
    int isempty()
    {
        if (front == NULL && rear == NULL)
        return 1;
        else
        return 0;
    }
    void peek()
    {
        if (front == NULL && rear == NULL)
        {
            cout<<"queue is empty\n";
        }
        else
        cout<<front->data<<endl;
    }
};
int main()
{
     Cqueue queue;
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