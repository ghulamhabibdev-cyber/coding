#ifndef H_TreeNode
#define H_TreeNode
#include <iostream>
using namespace std;

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
    int  getData();
    void setLeft(TreeNode * node);
    void setRight(TreeNode * node);
    TreeNode* &getLeft();
    TreeNode* &getRight();
};
TreeNode::TreeNode(int d)
{
    this->data=d;
    this->left=NULL;
    this->right=NULL;
}
TreeNode::TreeNode()
{
    this->data=0;
    this->left=NULL;
    this->right=NULL;
}
void TreeNode::setData(int data)
{
    this->data=data;
}
int TreeNode::getData()
{
    return data;
}
void TreeNode::setLeft(TreeNode * left)
{
    this->left=left;
}
void TreeNode::setRight(TreeNode * right)
{
    this->right=right;
}
TreeNode * &TreeNode::getLeft()
{
    return left;
}
TreeNode * &TreeNode::getRight()
{
    return right;
}

#endif