#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
node *create()
{
    int x;
    node *newnode;
    newnode = new node;
    cout<<"Enter data (-1 for no node): ";
    cin>>x;
    if (x == -1)
    return 0;
    newnode->data = x;
    cout<<"Enter left child of "<<x<<"\t";
    newnode->left = create();
    cout<<"Enter right child of "<<x<<"\t";
    newnode->right = create();
    return (newnode);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{

    node *root = NULL;
    root = create();
    cout<<"preorder: ";
    preorder(root);
    cout<<"\ninorder: ";
    inorder(root);
    cout<<"\npostorder: ";
    postorder(root);
    cout<<endl;
}