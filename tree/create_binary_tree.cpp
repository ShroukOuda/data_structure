#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
struct node *create()
{
    int x;
    node *newnode;
    newnode = new node;
    cout<<"\nEnter data (-1 for no node): ";
    cin>>x;
    if (x == -1)
    return 0;
    newnode->data = x;
    cout<<"Enter left child of "<<x;
    newnode->left = create();
    cout<<"Enter right child of "<<x;
    newnode->right = create();
    return (newnode);
}
int main()
{
    node *root;
    root = 0;
    root = create();
}