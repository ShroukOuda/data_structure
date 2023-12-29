#include <iostream>
using namespace std;
class clsCll
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
        if (head == 0)
        {
            head = tail = newnode;
            newnode->next = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
    }
    void display()
    {
        node *temp;
        temp = head;
        cout<<"list is:\n";
        while (temp->next != head)
        {
            cout<<temp->data<<' ';
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
    int length()
    {
        node *temp;
        int cnt = 0;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
            cnt++;
        }
        if (cnt)
        return (cnt + 1);
        return (cnt);
    }
    void insert_beg(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
    void insert_end(int x)
    {
        node *newnode;
        newnode = new node;
        newnode->data = x;
	if(head == NULL)
	{
		insert_beg(newnode->data);
	}
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
    void insert_at_pos(int pos, int x)
    {
        node *newnode, *temp = head;
        int i = 1;
        newnode = new node;
        newnode->data = x;
        if (pos == 1)
        {
            insert_beg(newnode->data);
        }
        else if (pos > length() && pos < 1)
        {
            cout<<"invaild position\n";
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
        node *temp = head;
        head = temp->next;
        tail->next = head;
        free(head);
    }
    void delete_end()
    {
        node *current = head, *previous;
        if (head == 0)
        cout<<"list is empty\n";
        else if (current->next == head)
        {
            head = tail = 0;
            free(current);
        }
        else
        {
        while (current->next != head)
        {
            previous = current;
            current = current->next;
        }
        previous->next = head;
        tail = previous;
        free(current);
        }
    }
    void delete_at_pos(int pos)
    {
        node *temp = head, *nextnode;
        int i = 1;
        if (pos > length() && pos < 1)
        {
            cout<<"invaild position\n";
        }
        else if (pos == 1)
        {
            delete_beg();
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
        }
    }
    void reverse()
    {
	    node *prev = tail, *cur = head, *nex;
	    while (nex != head)
	    {
		    nex = cur->next;
		    cur->next = prev;
		    prev = cur;
		    cur = nex;
	    }
	    tail = head;
	    head = prev;
    }
};
int main()
{
    clsCll list;
    list.create(8);
    list.create(9);
    list.create(4);
    list.display();
    cout<<list.length()<<endl;
    list.insert_beg(7);
    list.insert_end(1);
    list.insert_at_pos(1,6);
    list.display();
    list.delete_beg();
    list.delete_end();
    list.delete_at_pos(2);
    list.display();
    list.reverse();
    list.display();
}
