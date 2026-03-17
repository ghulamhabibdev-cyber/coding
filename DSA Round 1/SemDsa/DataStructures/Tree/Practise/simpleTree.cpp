#include <iostream>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
        this->leftNode = NULL;
        this->rightNode = NULL;
    }
};
void printNode(TreeNode *root);
void builTree(TreeNode *&root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return;
    }
    root = new TreeNode(data);
    cout << "Enter for left Node of " << root->data << endl;
    builTree(root->leftNode);
    cout << "Enter Data for right of " << root->data << endl;
    builTree(root->rightNode);
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
bool searchInTree(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    bool left = searchInTree(root->leftNode, key);
    bool right = searchInTree(root->rightNode, key);
    return left || right;
}
TreeNode *getMin(TreeNode *root)
{
    if (!root)
    {
        return nullptr;
    }
    TreeNode *left = getMin(root->leftNode);
    TreeNode *right = getMin(root->rightNode);
    if (!left && !right)
    {
        return root;
    }
    else if (!left && right)
    {
        if (right->data < root->data)
        {
            return right;
        }
        else
        {
            root;
        }
    }
    else if (left && !right)
    {
        if (left->data < root->data)
        {
            return left;
        }
        else
        {
            root;
        }
    }
    else if (left && right)
    {
        if (root->data < left->data && root->data < right->data)
        {
            return root;
        }
        if (left->data < root->data && left->data < right->data)
        {
            return left;
        }
        if (right->data < root->data && right->data < left->data)
        {
            return right;
        }
    }
    return root;
}
TreeNode *getMax(TreeNode *root)
{
    if (!root)
    {
        return root;
    }
    TreeNode *left = getMax(root->leftNode);
    TreeNode *right = getMax(root->rightNode);
    if (!left && !right)
    {
        return root;
    }
    else if (!left && right)
    {
        if (right->data > root->data)
        {
            return right;
        }
        else
        {
            root;
        }
    }
    else if (left && !right)
    {
        if (left->data > root->data)
        {
            return left;
        }
        else
        {
            root;
        }
    }
    else if (left && right)
    {
        if (root->data > left->data && root->data > right->data)
        {
            return root;
        }
        if (left->data > root->data && left->data > right->data)
        {
            return left;
        }
        if (right->data > root->data && right->data > left->data)
        {
            return right;
        }
    }
    return root;
}
void printNode(TreeNode *root)
{
    if (root)
    {
        cout << "CurrRoot Data " << root->data << endl;
    }
}
bool checkDuplicateHelper(TreeNode *root, unordered_set<int> &TreeSet)
{
    if (!root)
    {
        return false;
    }
    if (TreeSet.find(root->data) != TreeSet.end())
    {
        return true;
    }
    TreeSet.insert(root->data);
    bool leftHasDuplicate = checkDuplicateHelper(root->leftNode, TreeSet);
    bool rightHasDuplicate = checkDuplicateHelper(root->rightNode, TreeSet);
    return leftHasDuplicate || rightHasDuplicate;
}
bool checkDuplicates(TreeNode *root)
{
    unordered_set<int> mySet;
    return checkDuplicateHelper(root, mySet);
}
int countUniqNodesHelper(TreeNode *root, unordered_set<int> &myset)
{
    if (!root)
    {
        return 0;
    }
    int data = root->data;
    bool isUniqe = (myset.find(data) == myset.end());
    myset.insert(data);
    int leftCount = countUniqNodesHelper(root->leftNode, myset);
    int rightCount = countUniqNodesHelper(root->rightNode, myset);
    return leftCount + rightCount + (isUniqe ? 1 : 0);
}
int countUniqNodes(TreeNode *root)
{
    unordered_set<int> set;
    return countUniqNodesHelper(root, set);
}
int countDuplicatesHelper(TreeNode *root, unordered_set<int> &mySet)
{
    if (!root)
    {
        return 0;
    }
    int data = root->data;
    bool isDuplic = (mySet.find(data) != mySet.end());
    mySet.insert(data);
    int leftCount = countDuplicatesHelper(root->leftNode, mySet);
    int rightCount = countDuplicatesHelper(root->rightNode, mySet);
    int ans = leftCount + rightCount + (isDuplic ? 1 : 0);
    return ans;
}
int countDuplicates(TreeNode *root)
{
    unordered_set<int> mySet;
    return countDuplicatesHelper(root, mySet);
}
int getHeight(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int leftNodeHeight = getHeight(root->leftNode);
    int rightNodeHeight = getHeight(root->rightNode);
    int currHeight = 1 + max(leftNodeHeight, rightNodeHeight);
    return currHeight;
}
int totalNodes(TreeNode *root)
{
    if (!root)
    {
        return 0;
    }
    int leftNodeCount = totalNodes(root->leftNode);
    int rightNodeCount = totalNodes(root->rightNode);
    int currNodeCount = 1 + leftNodeCount + rightNodeCount;
    return currNodeCount;
}
main()
{
    TreeNode *root = NULL;
    cout << "Enter Root Data \n";
    builTree(root);
    cout << "PreOrderTraveral \n";
    preOrderTravesal(root);
    cout << endl;
    cout << "Inorder traversal \n";
    inorderTraversal(root);
    cout << endl;
    cout << "PostOrderTraversal \n";
    postOrderTraversal(root);
    cout << endl;
    cout << "Lever Order Traversal \n";
    levelOrderTraversal(root);
    int key = 1;
    while (key != -1)
    {
        cout << "Enter The key \n";
        cin >> key;
        bool isPresent = searchInTree(root, key);
        if (isPresent)
        {
            cout << "Key is Present in tree \n";
        }
        else
        {
            cout << "Key is Not Present in tree \n";
        }
    }
    printNode(getMin(root));
    printNode(getMax(root));
    bool isDuplicate = checkDuplicates(root);
    if (isDuplicate)
    {
        cout << "Duplicate<2> value is present in tree \n";
    }
    else
    {
        cout << "Not duplicate<0> value in tree \n";
    }
    int uniqueNode = countUniqNodes(root);
    int duplicates = countDuplicates(root);
    cout << "Total UniNodes----->        : " << uniqueNode << endl;
    cout << "Toal Duplicates Nodes-----> : " << duplicates << endl;
    cout << "==============================Jemp.x=====================================\n";
    cout << "Height Of Tree : " << getHeight(root) << endl;
    cout << "Lever of Tree : " << getHeight(root) - 1 << endl;
    cout << "Total Nodes : " << totalNodes(root) << endl;
    return 0;
}