#include <iostream>
using namespace std;

class Node
{
public:
    int data, height;
    Node *left, *right;
    Node(int d)
    {
        this->data = d;
        height = 1;
        right = left = NULL;
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

int getBalanceIndex(Node *root)
{
    if (!root)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node *rightRotation(Node *root)
{
    Node *child = root->left;
    Node *childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *leftRotation(Node *root)
{
    Node *child = root->right;
    Node *childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

Node *insert(Node *root, int data)
{
    // Base case
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
        return root; // Duplicate values not allowed

    // Update height of node after insertion
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Check balance factor of current node
    int balance = getBalanceIndex(root);

    // Left Left case:
    if (balance > 1 && data < root->left->data)
    {
        return rightRotation(root);
    }
    // Right Right case
    else if (balance < -1 && data > root->right->data)
    {
        return leftRotation(root);
    }
    // Left Right case
    else if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // Right Left case
    else if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // No rotation needed
    else
        return root;
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
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);

    cout << "PreOrder : " << endl;
    preOrder(root);
    cout<<"Inorder : "<<endl;
    inorder(root);
    cout << endl;

    return 0;
}