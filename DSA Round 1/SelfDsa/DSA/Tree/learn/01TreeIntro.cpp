#include <iostream>
using namespace std;
class TreeNode
{
private:
    int data;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    }
    // TreeNode(int *);
    int GetData()
    {
        return data;
    }
    void SetData(int data)
    {
        this->data = data;
    }
    TreeNode *GetLeft()
    {
        return left;
    }
    void SetLeft(TreeNode *lef)
    {
        this->left = lef;
    }
    TreeNode *GetRight()
    {
        return right;
    }
    void SetRight(TreeNode *righ)
    {
        this->right = right;
    }
    bool IsLeaf()
    {
        return true;
    }
    TreeNode *buildTree()
    {
        int data;
        cin >> data;

        if (data == -1)
            return nullptr;

        TreeNode *root = new TreeNode();
        root->SetData(data);
        root->SetLeft(buildTree());
        root->SetRight(buildTree());

        return root;
    }
};
// TreeNode *buildTree(TreeNode *root, int data)
// {
//     root = new TreeNode();
//     root->SetData(data);
//     if (data == -1)
//     {
//         return 0;
//     }
//     // cout << "Enter data to insert left of  " << data << endl;
//     root->SetLeft(buildTree(root->GetLeft(), data));
//     // cout << "Enter data to insert right of  " << data << endl;
//     root->SetRight(buildTree(root->GetLeft(), data));
//     return root;
// }
void preOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->GetData() << " ";
    preOrder(root->GetLeft());
    preOrder(root->GetRight());
}
void postOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->GetLeft());
    postOrder(root->GetRight());
    cout << root->GetData() << " ";
}
int main()
{
    TreeNode *t;
    t = t->buildTree();
    preOrder(t);
    cout << endl;
    postOrder(t);

    return 0;
}
