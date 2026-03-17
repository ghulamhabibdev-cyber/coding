#include <iostream>
using namespace std;


class TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int data;

public:
    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode()
    {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    void setData(int data)
    {
        this->data = data;
    }
    int getData()
    {
        return data;
    }
    void setLeft(TreeNode *node)
    {
        this->left = node;
    }
    void setRight(TreeNode *node)
    {
        this->right = node;
    }
    TreeNode *getLeft()
    {
        return left;
    }
    TreeNode *getRight()
    {
        return right;
    }
};
TreeNode * BuildMaxHeap(TreeNode * root)
{
    
}

int main() {
    

    return 0;
}