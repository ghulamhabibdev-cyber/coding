#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertData(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertData(root->right, data);
    }
    else
    {
        root->left = insertData(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertData(root, data);
        cin >> data;
        /* code */
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorderTraver(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraver(root->left);
    cout << root->data << " ";
    inorderTraver(root->right);
}
bool searchInBST(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (root->data > data)
    {
        return searchInBST(root->right, data);
    }
    else
    {
        return searchInBST(root->left, data);
    }
}
Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
// deletion in binary search tree
Node *deletionInBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 chil
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child case
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child case
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletionInBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletionInBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deletionInBST(root->right, val);
        return root;
    }
    return NULL;
}
int main()
{
    //10 8 2 3 21 23 11 1 -1
    //50 60 20 10 30 40 90 60 70 80 -1
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    // root=deletionInBST(root,50);
    // inorderTraver(root);
    return 0;
}