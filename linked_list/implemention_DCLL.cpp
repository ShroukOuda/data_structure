#include <iostream>
using namespace std;
class clsDcll
{
    struct node
    {
        int data;
        node *next;
        node *prev;
    }*head = NULL, *tail = NULL;
    public:
    void create(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        newnode->next = 0;
        newnode->prev = 0;
        if (head == NULL)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
    }
    void display()
    {
        node *temp;
        temp = head;
        if (head == 0)
        cout<<"list is empty\n";
        else
        {
        cout<<"list is:\n";
        while (temp != tail)
        {
            cout<<temp->data<<' ';
            temp = temp->next;
        }
        cout<<temp->data<<endl;
        }
    }
    int length()
    {
        node *temp;
        temp = head;
        if (temp == 0)
        return 0;
        int cnt = 1;
        while (temp != tail)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    void insert_beg(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        if (head == 0)
        {
            head = tail = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else
        {
        head->prev = newnode;
        newnode->prev = tail;
        newnode->next = head;
        tail->next = newnode;
        head = newnode;
        }
    }
    void insert_end(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        if (head == 0)
        {
            head = tail = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else
        {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
        }
    }
    void insert_at_pos(int pos, int x)
    {
        node *newnode, *temp;
        int i = 1;
        temp = head;
        newnode = new node;
        newnode->data = x;
        if (pos < 1 || pos > length())
        {
        cout<<"InVaild position\n";
        }
        else if (pos == 1)
        {
        insert_beg(newnode->data);
        }
        else
        {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
        }
    }
    void delete_beg()
    {
        node *temp;
        temp = head;
        if (head == 0)
        {
        cout<<"list is empty\n";
        }
        else if (head == tail)
        {
            head = tail = 0;
            free(temp);
        }
        else
        {
        head = temp->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
        }
    }
    void delete_end()
    {
        node *temp;
        temp = tail;
        if (head == 0)
        {
        cout<<"list is empty\n";
        }
        else if (head == tail)
        {
            head = tail = 0;
            free(temp);
        }
        else
        {
        tail = temp->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
        }
    }
    void delete_at_pos(int pos)
    {
        node *temp;
        int i = 1;
        temp = head;
        if (head == 0)
        {
        cout<<"list is empty\n";
        }
        else if (pos < 1 || pos > length())
        {
        cout<<"InVaild position\n";
        }
        else if (pos == 1)
        {
        delete_beg();
        }
        else
        {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp->next == head)
        tail = temp->prev;
        free(temp);
        }
    }
    void reverse()
    {
       node *temp, *nextnode;
       temp = head;
       while (temp != tail)
       {
         nextnode = temp->next;
         temp->next = temp->prev;
         temp->prev = nextnode;
         temp = nextnode;
       }
       nextnode = temp->next;
       temp->next = temp->prev;
       temp->prev = nextnode;
       temp = head;
       head = tail;
       tail = temp;
    }
};
int main()
{
    clsDcll list;
    list.create(9);
    list.create(5);
    list.display();
    cout<<list.length()<<endl;
    list.insert_beg(1);
    list.insert_end(8);
    list.insert_at_pos(2,7);
    list.display();
    cout<<list.length()<<endl;
    list.reverse();
    list.display();
    list.delete_beg();
    list.delete_end();
    list.delete_at_pos(2);
    list.display();
    cout<<list.length()<<endl;
}