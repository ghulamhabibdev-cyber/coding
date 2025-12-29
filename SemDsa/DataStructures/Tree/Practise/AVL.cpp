#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TreeNode
{
public:
    int data;
    int height;
    TreeNode *leftNode;
    TreeNode *rightNode;

public:
    TreeNode()
    {
        this->data = 0;
        height = 0;
        this->leftNode = 0;
        this->rightNode = 0;
    }
    TreeNode(int data)
    {
        this->data = data;
        this->height = 1;
        this->leftNode = 0;
        this->rightNode = 0;
    }
};
int getHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    return root->height;
}
int getBalanceFactor(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int ans = getHeight(root->leftNode) - getHeight(root->rightNode);
    return ans;
}
TreeNode *rightRotation(TreeNode *root)
{
    TreeNode *child = root->leftNode;
    TreeNode *childRight = child->rightNode;
    child->rightNode = root;
    root->leftNode = childRight;
    root->height = 1 + max(getHeight(root->leftNode), getHeight(root->rightNode));
    child->height = 1 + max(getHeight(child->leftNode), getHeight(child->rightNode));
    return child;
}
TreeNode *leftRotation(TreeNode *root)
{
    TreeNode *child = root->rightNode;
    TreeNode *childLeft = child->leftNode;
    child->leftNode = root;
    root->rightNode = childLeft;
    root->height = 1 + max(getHeight(root->leftNode), getHeight(root->rightNode));
    child->height = 1 + max(getHeight(child->leftNode), getHeight(child->rightNode));
    return child;
}
TreeNode *BuildAVL(TreeNode *&root, int data)
{
    if (!root)
    {
        return new TreeNode(data);
    }
    if (data < root->data)
    {
        root->leftNode = BuildAVL(root->leftNode, data);
    }
    else if (data > root->data)
    {
        root->rightNode = BuildAVL(root->rightNode, data);
    }
    else
    {
        return root;
    }
    root->height = 1 + max(getHeight(root->leftNode), getHeight(root->rightNode));
    int blnFact = getBalanceFactor(root);
    // left left
    if (blnFact > 1 && data < root->leftNode->data)
    {
        return rightRotation(root);
    }
    // right right case :
    else if (blnFact < -1 && data > root->rightNode->data)
    {
        return leftRotation(root);
    }
    // left right case :
    else if (blnFact > 1 && data > root->leftNode->data)
    {
        root->leftNode = leftRotation(root->leftNode);
        return rightRotation(root);
    }
    // right left case :
    else if (blnFact < -1 && data < root->rightNode->data)
    {
        root->rightNode = rightRotation(root->rightNode);
        return leftRotation(root);
    }
    return root;
}
void levelOrderTraversal(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> treeQ;
    treeQ.push(root);
    treeQ.push(NULL);
    while (!treeQ.empty())
    {
        TreeNode *currNode = treeQ.front();
        treeQ.pop();
        if (currNode == nullptr)
        {
            cout << endl;
            if (!treeQ.empty())
            {
                treeQ.push(nullptr);
            }
        }
        else
        {
            cout << (currNode->data) << " ";
            if (currNode->leftNode)
            {
                treeQ.push(currNode->leftNode);
            }
            if (currNode->rightNode)
            {
                treeQ.push(currNode->rightNode);
            }
        }
    }
}
int main()
{
    int data = 1;
    cout << "Enter data \n for exit -1\n ";
    TreeNode *root = NULL;
    while (data != -1)
    {
         cout << "Enter Data : " << endl;
        cin >> data;
        if (data != -1)
        {
            root = BuildAVL(root, data);
            cout<<"\n======================================================\n";
           
            levelOrderTraversal(root);
           cout<<"\n======================================================\n";
        }
    }
    int currentBlnFact=getBalanceFactor(root);
    cout<<"current balance Factor : "<<currentBlnFact<<endl;

    return 0;
}