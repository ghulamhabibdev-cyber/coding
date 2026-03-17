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
    TreeNode *leftNode;
    TreeNode *rightNode;

public:
    TreeNode()
    {
        this->data = 0;
        this->leftNode = 0;
        this->rightNode = 0;
    }
    TreeNode(int data)
    {
        this->data = data;
        this->leftNode = 0;
        this->rightNode = 0;
    }
};
TreeNode *buildBST(TreeNode *&root, int data)
{
    if (!root)
    {
        return new TreeNode(data);
    }
    if (data < root->data)
    {
        root->leftNode = buildBST(root->leftNode, data);
    }
    else if (data > root->data)
    {
        root->rightNode = buildBST(root->rightNode, data);
    }
    return root;
}
void preOrderTravesal(TreeNode *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrderTravesal(root->leftNode);
        preOrderTravesal(root->rightNode);
    }
}
void inorderTraversal(TreeNode *root)
{
    if (root)
    {

        inorderTraversal(root->leftNode);
        cout << root->data << " ";
        inorderTraversal(root->rightNode);
    }
}
void postOrderTraversal(TreeNode *root)
{
    if (root)
    {

        postOrderTraversal(root->leftNode);
        postOrderTraversal(root->rightNode);
        cout << root->data << " ";
    }
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
            cout << (currNode->data);
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
bool searchBST(TreeNode *root, int key)
{
    if (!root)
    {
        return false;
    }
    int data = root->data;
    if (data == key)
    {
        return true;
    }
    bool left;
    bool right;
    if (key < data)
    {
        left = searchBST(root->leftNode, key);
    }
    if (key > data)
    {
        right = searchBST(root->rightNode, key);
    }
    return left || right;
}
// helper functions for deletion of tree
TreeNode *findRootRightLastLeft(TreeNode *root)
{
    if (!root->rightNode)
    {
        return root;
    }
    return findRootRightLastLeft(root->rightNode);
}
TreeNode *deletionHelperBST(TreeNode *root)
{
    if (root->leftNode == NULL)
    {
        TreeNode *temp = root;
        TreeNode *right = root->rightNode;
        delete temp;
        return right;
    }
    if (root->rightNode == NULL)
    {
        TreeNode *temp = root;
        TreeNode *left = root->leftNode;
        delete temp;
        return left;
    }
    TreeNode *temp = root;
    TreeNode *rootRight = root->rightNode;
    TreeNode *lastLeftRight = findRootRightLastLeft(root->leftNode);
    lastLeftRight->rightNode = rootRight;
    TreeNode *left = root->leftNode;
    delete temp;
    return left;
}
TreeNode *deleteNodeInBST(TreeNode *root, int key)
{
    if (!root)
    {
        return root;
    }
    if (key < root->data)
    {
        root->leftNode = deleteNodeInBST(root->leftNode, key);
        return root;
    }
    if (key > root->data)
    {
        root->rightNode = deleteNodeInBST(root->rightNode, key);
        return root;
    }
    else
    {
     return   deletionHelperBST(root);
    }
}
int main()
{
    cout << "==================================BST===================================\n";
    TreeNode *root = NULL;
    int data = 1;
    cout << "To Exit -1 \n";
    while (data != -1)
    {
        cout << "Enter data To Node \n";
        cin >> data;
        if (data != -1)
        {
            root = buildBST(root, data);
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "PreOrder Traveral \n";
    preOrderTravesal(root);
    cout << "Inorder Traversal \n";
    inorderTraversal(root);
    cout << endl;
    cout << "Post Order Traversal \n";
    postOrderTraversal(root);
    cout << endl;
    cout << "Lever Order Traversal \n";
    levelOrderTraversal(root);
    cout << endl;
    int key = 1;
    while (key != -1)
    {
        cout << "Enter key \n";
        cin >> key;
        bool isPresent = searchBST(root, key);
        if (isPresent)
        {
            cout << key << " is present  \n";
        }
        else
        {
            cout << key << "is Not present \n";
        }
    }
    cout << "==========================Deletion In BST===============================\n";
    int delKey = 1;
    while (delKey != -1)
    {
        cout << "Enter deletion Node \n";
        cin >> delKey;
        root = deleteNodeInBST(root, delKey);
        // cout<<endl;
        inorderTraversal(root);
        cout << endl;
    }

    return 0;
}