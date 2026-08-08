/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> func(TreeNode * root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int>lPair=func(root->left);
        pair<int,int>rPair=func(root->right);
        if(root->left==NULL&&root->right==NULL)
        {
            return {root->val,1};
        }
        int lHeight=lPair.second;
        int rHeight=rPair.second;
      
        if(lHeight>rHeight)
        {
            lPair.second+=1;
            return lPair;
        }
        else if(rHeight>lHeight)
        {
            rPair.second+=1;
            return rPair;
        }
        cout<<"Root : "<<root->val<<" lPair : "<<lPair.first<<" rPari : "<<rPair.first<<endl;
        lPair.first+=rPair.first;
        lPair.second+=1;
        return lPair;
    }
    int deepestLeavesSum(TreeNode* root) {
        pair<int,int>p=func(root);
        int res=p.first;
        return res;
        return 0;
    }
};