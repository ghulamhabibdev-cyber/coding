#include <iostream>
// #include "TreeNode.h"
using namespace std;
#include<queue>
class TreeNode
{
private:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int d);
    TreeNode();
    void setData(int data);
    int getData();
    void setLeft(TreeNode *node);
    void setRight(TreeNode *node);
    TreeNode *getLeft();
    TreeNode *getRight();
};
TreeNode::TreeNode(int d)
{
    this->data = d;
    this->left = NULL;
    this->right = NULL;
}
TreeNode::TreeNode()
{
    this->data = 0;
    this->left = NULL;
    this->right = NULL;
}
void TreeNode::setData(int data)
{
    this->data = data;
}
int TreeNode::getData()
{
    return data;
}
void TreeNode::setLeft(TreeNode *left)
{
    this->left = left;
}
void TreeNode::setRight(TreeNode *right)
{
    this->right = right;
}
TreeNode *TreeNode::getLeft()
{
    return left;
}
TreeNode *TreeNode::getRight()
{
    return right;
}
TreeNode *helpInsert(TreeNode *root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    if (root == NULL)
        root = new TreeNode();

    root->setData(data);
    cout << "Enter for Left of : " << root->getData() << endl;
    root->setLeft(helpInsert(root->getLeft()));
    cout << "Enter for Right of : " << root->getData() << endl;
    root->setRight(helpInsert(root->getRight()));
    return root;
}
void Inorder(TreeNode *root)
{
    if (root)
    {
        Inorder(root->getLeft());
        cout << root->getData() << " ";
        Inorder(root->getRight());
    }
}
void preOrder(TreeNode *root)
{
    if (root)
    {
        cout << root->getData() << " ";
        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}
void postOrder(TreeNode *root)
{
    if (root)
    {
        postOrder(root->getLeft());
        postOrder(root->getLeft());
        cout << root->getData() << " ";
    }
}
void levelOrderTraversal(TreeNode * root)
{
    if(root==NULL)
    {
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        TreeNode * temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }

        }
        else{
            cout<<temp->getData()<<" ";
            if(temp->getLeft())
            {
                q.push(temp->getLeft());
            }
            if(temp->getRight())
            {
                q.push(temp->getRight());
            }
        }
    }


}

int main()
{
    TreeNode *root = NULL;
    root = helpInsert(root);
    // postOrder(root);
    levelOrderTraversal(root);
    return 0;
}