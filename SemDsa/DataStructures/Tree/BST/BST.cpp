#include <iostream>
#include<queue>
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
void preOrder(TreeNode *root)
{
    if (root)
    {
        cout << root->getData() << " ";
        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}
void inOrder(TreeNode *root)
{
    if (root)
    {

        inOrder(root->getLeft());
        cout << root->getData() << " ";
        inOrder(root->getRight());
    }
}
void postOrder(TreeNode *root)
{
    if (root)
    {

        postOrder(root->getLeft());
        postOrder(root->getRight());
        cout << root->getData() << " ";
    }
}
TreeNode *createBSt(TreeNode *root, int data)
{
    if (root == NULL)
    {
        TreeNode *node = new TreeNode(data);
        root = node;
        return root;
    }
    if (root->getData() > data)
    {
        root->setLeft(createBSt(root->getLeft(), data));
    }
    if (root->getData() < data)
    {
        root->setRight(createBSt(root->getRight(), data));
    }
    return root;
}
bool checkEmpty(TreeNode *root)
{
    if (root == NULL)
        return 1;
    return 0;
}
int countNode(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = countNode(root->getLeft());
    int right = countNode(root->getRight());
    int ans = 1 + (left + right);
    return ans;
}
int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->getLeft());
    int right = height(root->getRight());
    int ans = 1 + max(left, right);
    return ans;
}
bool isBalance(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lHeight = height(root->getLeft());
    int rHeight = height(root->getRight());
    int ans = abs(lHeight - rHeight);
    if (ans > 1)
    {
        return false;
    }
    return isBalance(root->getLeft()) && isBalance(root->getRight());
}
int findMin(TreeNode *root)
{

    if (root == NULL)
        return INT_MAX;

    int lefty = findMin(root->getLeft());
    int righty = findMin(root->getRight());
    int roAns = root->getData();
    if (lefty < roAns && lefty < righty)
        return lefty;
    if (righty < roAns && righty < lefty)
        return righty;
    return roAns;
}
int findMax(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int lefty = findMax(root->getLeft());
    int righty = findMax(root->getRight());
    int rooty = root->getData();
    if (lefty > righty && lefty > rooty)
        return lefty;
    if (righty > lefty && righty > rooty)
        return righty;
    return rooty;
}
TreeNode *copyBst(TreeNode *copyTree, TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Correct the assignment!
    copyTree = new TreeNode(root->getData());

    copyTree->setLeft(copyBst(copyTree->getLeft(), root->getLeft()));
    copyTree->setRight(copyBst(copyTree->getRight(), root->getRight()));

    return copyTree;
}
void levelOrderTraversal(TreeNode * root)
{
    if(root==NULL)
    {
        return ;
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
            cout<<" " <<temp->getData()<<
            " ";
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
    cout << checkEmpty(root);
    root = createBSt(root, 10);
    root = createBSt(root, 2);
    cout << endl;
    cout << checkEmpty(root);
    cout << endl;
    root = createBSt(root, 11);
    root = createBSt(root, 13);
    root = createBSt(root, 14);
    root = createBSt(root, 15);
    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
    //   cout<<endl;

    // inOrder(root);
    cout << endl;
    // cout<<endl;
    // cout << countNode(root);
    // cout << endl;
    // cout << height(root);
    // cout << endl;
    // cout << isBalance(root);
    // cout<<endl;
    // cout<<endl;
    // cout<<findMin(root);
    // cout<<endl;
    // cout<<endl;
    // cout<<findMax(root);
    TreeNode *copyTree = NULL;
    copyTree = copyBst(copyTree, root);
    cout << endl;
    // inOrder(copyTree);
    levelOrderTraversal(copyTree);

    return 0;
}