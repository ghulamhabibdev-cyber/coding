#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
void BuildTree(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val)
    {
        BuildTree(root->left, val);
    }
    else
    {
        BuildTree(root->right, val);
    }
}
void takeInput(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        BuildTree(root, data);
        cin >> data;
    }
}
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
void morrisInorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    TreeNode *predecessor;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;

                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}
//

TreeNode *buildTree(TreeNode *root)
{
    cout << "Enter the data for node\n";
    int data;
    cin >> data;
    root = new TreeNode(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data to insert left of  " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to insert right of  " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
//
//

int solve(TreeNode *&root, int target, int parent)
{
    if (root == NULL)
    {
        return 0;
    }
    parent = root->val;
    int left = solve(root->left, target, parent);
    int right = solve(root->right, target, parent);
    int rootVal = root->val;
    if ((rootVal < parent || rootVal < target) &&
        (rootVal < right || right == 0) && (left < rootVal))
    {
        cout << "Ok av set " << root->val << endl;
        return 0;
    }
    else if ((rootVal > parent || rootVal > target) &&
             (left < rootVal || left == 0) &&
             (right > rootVal || right == 0))
    {
        cout << "Ok av set " << root->val << endl;
        return 0;
    }
    else
    {
        cout << "Befor change  : " << root->val << endl;
        root->val = target;
        cout << "after change  : " << root->val << endl;

        return root->val;
    }
}

void recoverTree2(TreeNode *&root)
{

    int target = root->val;
    int parent = root->val;
    target = solve(root, target, parent);
    root->val = target;
}

//
void bulidFromLevelOrder2(TreeNode *&root)
{
    queue<TreeNode *> q;
    cout << "Enter data for root \n";
    int data;
    cin >> data;

    root = new TreeNode(data);
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << "Enter data for left of : " << temp->val << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }
        cout << "Enter data for right of : " << temp->val << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *temp = q.front();

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
            cout << temp->val << " ";
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
// if(predecessor->val<curr->val && curr->val)
void findToReplace(TreeNode *&root)
{
    TreeNode *curr = root;
    TreeNode *predecessor;
    bool flag = true;
    int target = root->val;
    int getVal = INT_MAX;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {

            if (curr->val > target && flag == true)
            {
                getVal = curr->val;
                curr->val = target;
                flag = false;
            }
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                if (predecessor->val < curr->val && predecessor->val > target)
                {
                    cout << "ok i ma i wirhg part \n";
                }
                else if (predecessor->val < curr->val && predecessor->val < target)
                {
                    getVal = predecessor->val;
                    predecessor->val = target;
                }
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << curr->val << " ";
                if (curr->val < curr->right->val)
                {
                    cout << "I am changing \n";
                    getVal = curr->right->val;
                    curr->val = curr->right->val;
                }
                else
                {
                    cout << "I am changing \n";
                    getVal = curr->right->val;
                    curr->right->val = target;
                }
                curr = curr->right;
            }
        }
        cout << "Value of Curr : << " << curr->val << endl;
    }
    root->val = getVal;
}

void recoverTree(TreeNode *&root)
{
    findToReplace(root);
}
int main()
{
    TreeNode *root = NULL;
    // takeInput(root);
    // inorderTraversal(root);
    // morrisInorderTraversal(root);
    root = buildTree(root);
    // bulidFromLevelOrder2(root);
    // recoverTree(root);
    // findToReplace(root);
    recoverTree(root);
    // levelOrderTraversal(root);
    inorderTraversal(root);

    return 0;
}