#include <iostream>
using namespace std;
class Btree{
    public:
    struct node{
        int data;
        node *left;
        node *right;
    }*root;
    node *addroot(int x)
    {
        node *newnode;
        newnode = new node;
        if (newnode != NULL)
        {
            newnode->left = NULL;
            newnode->right = NULL;
            newnode->data = x;
            root = newnode;
        }
        return newnode;
    }
    node *insertleft(node *parent, int x)
    {
        if (parent == NULL)
        {
            cout<<"parent is null, then cannot insert left child\n";
            return NULL;
        }
        node *newnode = new node;
        newnode->data = x;
        parent->left = newnode;
        return newnode;
    }
    node *insertright(node *parent, int x)
    {
        if (parent == NULL)
        {
            cout<<"parent is null, then cannot insert right child\n";
            return NULL;
        }
        node *newnode = new node;
        newnode->data = x;
        parent->right = newnode;
        return newnode;
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
  int isempty()
  {
    if (root == NULL)
    return 1;
    return 0;
  }
  int size(node *root)
  {
    if (root == NULL)
    {
        return 0;
    }
    return 1 + size(root->left) + size(root->right);
  }
  int isroot(node *r)
  {
    if (r == root)
    return 1;
    return 0;
  }
  /*int depth_node(node *n)
  {

  }*/
  int height_node(node *n)
  {
    if (n == NULL)
    return -1;
    int leftheight = height_node(n->left);
    int rightheight = height_node(n->right);


    return max(leftheight, rightheight) + 1;
  }
  /*void depth_tree()
  {
    cout<<depth_node(root);
  }*/
  void height_tree()
  {
  cout<<height_node(root);
  }
  /*
  int degree_node(node *n)
  {

  }
  int degree_tree()
  {

  }
  int isInternal(node *n)
  {

  }
  int isExtrenal(node *n)
  {

  }
  void ancestors(node *n)
  {

  }
  void decendants(node *n)
  {

  }
  void parent(node *n)
  {

  }
  void sibling(node *n)
  {

  }
  */
};
int main()
{
    Btree tree;
    Btree::node *root = tree.addroot(5);
    Btree::node *ch1 = tree.insertleft(root, 7);
    Btree::node *ch2 = tree.insertright(root, 8);
    tree.insertleft(ch1, 9);
    tree.insertright(ch1, 1);
    tree.insertleft(ch2, 2);
    tree.insertright(ch2, 3);
    cout<<"inorder: ";
    tree.inorder(root);
    cout<<"\npreorder: ";
    tree.preorder(root);
    cout<<"\npostorder: ";
    tree.postorder(root);
    cout<<endl;
    cout<<"size of tree is: "<<tree.size(root)<<endl;
    cout<<tree.isempty()<<endl;
   // cout<<"depth tree: ";
    //tree.depth_tree();
    cout<<"\nheight tree: ";
    tree.height_tree();
    //cout<<"\ndepth "<<ch1->data<<": "<<tree.depth_node(ch1)<<endl;
    cout<<"\nheight "<<ch1->data<<": "<<tree.height_node(ch1)<<endl;
    cout<<tree.isroot(ch1)<<endl;
}
