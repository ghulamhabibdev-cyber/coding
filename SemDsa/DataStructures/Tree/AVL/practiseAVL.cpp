#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};
int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}
int getBalance(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
Node *leftRotataion(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;
    child->left = root;
    root->right = childLeft;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(root->right));
    return child;
}
Node *rightRotataion(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;
    child->right = root;
    root->left = childRight;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(root->right));
    return child;
}
Node *insert(Node *root, int data)
{
    if (!root)
    {
        return new Node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        return root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balace = getBalance(root);
    // left left case
    if (balace > 1 && data < root->left->data)
    {
        return rightRotataion(root);
    }
    else if (balace < -1 && data > root->right->data)
    {
        return leftRotataion(root);
    }
    // left right case
    else if (balace > 1 && data > root->left->data)
    {
        root->left = leftRotataion(root->left);
        return rightRotataion(root);
    }
    else if (balace < -1 && data < root->right->data)
    {
        root->right = rightRotataion(root->right);
        return leftRotataion(root);
    }
    else
    {
        return root;
    }
}
void preOrder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(Node *root)
{
    if (root)
    {

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root)
    {

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    // root = insert(root, 95);

    cout << "PreOrder : " << endl;
    preOrder(root);
    cout<<"\nInorder : "<<endl;
    inOrder(root);
    cout << endl;

    return 0;
}