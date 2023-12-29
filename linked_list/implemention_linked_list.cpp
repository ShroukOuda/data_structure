#include <iostream>
using namespace std;
class clsLinkedList
{
    struct node
    {
        int data;
        node *next;
    }*head = NULL, *tail = NULL;
    public:
    void create(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        newnode->next = 0;
        if (head == NULL)
        head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    int length()
    {
        int cnt = 0;
        node *temp = head;
        while (temp != 0)
        {
            temp = temp->next;
            cnt++;
        }
        return (cnt);
    }

    void insert_beg(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }
    void insert_end(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        tail->next = newnode;
        tail = newnode;
    }
    void insert_at_pos(int pos, int x)
    {
        int i = 1;
        node *newnode, *temp;
        newnode = new node;
        newnode->data = x;
        temp = head;
        if (pos > length() || pos < 0)
        {
            cout<<"Invaild position\n";
        }
        else
        {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        }
    }
    
    void delete_beg()
    {
        node *temp;
        temp = head;
        head = temp->next;
        free(temp);
    }
    void delete_end()
    {
        node *temp;
        temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            head = tail = 0;
            free(temp);
        }
        else
        {
        tail = temp;
        temp = temp->next;
        free(temp);
        tail->next = NULL;
        }
    }
    void delete_at_pos(int pos)
    {
        int i = 1;
        node *temp, *nextnode;
        temp = head;
        if (pos == 1)
        delete_beg();
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
    void reverse()
    {
        node *prev, *cur, *nextnode;
        prev = 0;
        cur = nextnode = head;
        while (nextnode != 0)
        {
            nextnode = nextnode->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        tail = head;
        head = prev;
    }
    void display()
    {
        node *temp;
        temp = head;
        while (temp != 0)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};
int main()
{
    clsLinkedList l;
    l.create(8);
    l.create(6);
    l.create(3);
    cout<<l.length()<<endl;
    l.display();
    cout<<"************************\n";
    l.insert_beg(5);
    l.insert_end(1);
    l.insert_at_pos(3, 99);
    cout<<l.length()<<endl;
    l.display();
    cout<<"*************************\n";
    l.delete_beg();
    l.delete_end();
    l.delete_at_pos(2);
    cout<<l.length()<<endl;
    l.display();
    l.reverse();
    l.display();
}
