/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    void countGood(TreeNode *root, int prev, int &count)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val >= prev)
        {
            count++;
        }
        prev = max(prev, root->val);
        countGood(root->left, prev, count);
        countGood(root->right, prev, count);
    }
    int goodNodes(TreeNode *root)
    {
        int count = 0;
        countGood(root, root->val, count);
        // countGood(root->right,root->val,count);
        return count;
    }
};