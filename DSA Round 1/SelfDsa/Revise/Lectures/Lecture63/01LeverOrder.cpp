#include <iostream>
#include<queue>
using namespace std;
class node
{
private:
    int data;
    node *left;
    node *right;

public:
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    node()
    {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    void setData(int d)
    {
        this->data = d;
    }
    int getData()
    {
        return data;
    }
    void setLeft(node *temp)
    {
        this->left = temp;
    }
    node *getLeft()
    {
        return left;
    }
    void setRight(node *temp)
    {
        this->right = temp;
    }
    node *getRight()
    {
        return right;
    }
};
node *bulidTree(node *root)
{
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return nullptr;
    }
    cout << "Enter Data For left :" << root->getData() << "\n";
    root->setLeft(bulidTree(root->getLeft()));
    cout << "Enter Data For Right :" << root->getData() << endl;
    root->setRight(bulidTree(root->getRight()));
    return root;
}
void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->getLeft());
    cout << root->getData() << " ";
    inOrderTraversal(root->getRight());
}
void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->getData() << " ";
    preOrder(root->getLeft());
    preOrder(root->getRight());
}
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->getLeft());
    postOrder(root->getRight());
    cout << root->getData() << " ";
}
void levelOrderTraversal(node * root)
{
    queue<node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty())
    {
        node * temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}
int main()
{
    // 12 22 32 -1 -1 323 23 44 434 -1 -1 -1 -1 -1 -1 -1 -1 -1
    node *tree;
    tree = bulidTree(tree);
    cout << "Inorder Traversal \n";
    inOrderTraversal(tree);
    cout << endl;
    cout << "PreOrder Traversal \n";
    preOrder(tree);
    cout << endl;
    cout << "PostOrder Traversal \n";
    postOrder(tree);
    return 0;
}
