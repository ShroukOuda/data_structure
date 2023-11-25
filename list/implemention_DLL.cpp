#include <iostream>
using namespace std;
class clsDll
{
    private:
    struct node
    {
        int data;
        node *next;
        node *prev;
    }*head = NULL,*tail = NULL;
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
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    void display()
    {
        node *temp;
        temp = head;
        cout<<"list is:\n";
        while (temp != 0)
        {
            cout<<temp->data<<' ';
            temp = temp->next;
        }
        cout<<endl;
    }
    int length()
    {
        node *temp;
        temp = head;
        int cnt = 0;
        while (temp != 0)
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
        head->prev = newnode;
        newnode->prev = 0;
        newnode->next = head;
        head = newnode;
    }
    void insert_end(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = 0;
        tail = newnode;
    }
    void insert_at_pos(int pos, int x)
    {
        node *newnode, *temp;
        int i = 1;
        temp = head;
        newnode = new node;
        newnode->data = x;
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
    void delete_beg()
    {
        node *temp;
        temp = head;
        head = temp->next;
        head->prev = 0;
        free(temp);
    }
    void delete_end()
    {
        node *temp;
        temp = tail;
        tail = temp->prev;
        tail->next = 0;
        free(temp);
    }
    void delete_at_pos(int pos)
    {
        node *temp;
        int i = 1;
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    void reverse()
    {
       node *temp, *nextnode;
       temp = head;
       while (temp != 0)
       {
         nextnode = temp->next;
         temp->next = temp->prev;
         temp->prev = nextnode;
         temp = nextnode;
       }
       temp = head;
       head = tail;
       tail = temp;
    }
};
int main()
{
    clsDll list;
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