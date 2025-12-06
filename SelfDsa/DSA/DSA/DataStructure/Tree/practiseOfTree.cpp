#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter data for node\n";
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter left node for : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right node for : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
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
            cout << temp->data << " ";
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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);
    int heihgDia = height(root->left) + 1 + height(root->right);
    int ans = max(leftDia, max(rightDia, heihgDia));
    return ans;
}
pair<int, int> fastDiameter(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = fastDiameter(root->left);
    pair<int, int> right = fastDiameter(root->right);
    int leftAns = left.first;
    int rightAns = right.first;
    int heigDia = left.second + 1 + right.second;
    pair<int, int> ans;
    ans.first = max(leftAns, max(rightAns, heigDia));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
bool isBalanceTree(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = isBalanceTree(root->left);
    bool right = isBalanceTree(root->right);
    bool diff = abs(height(root->left) - height(root->left)) <= 1;
    if (left && right && diff)
    {
        return true;
    }
    return false;
}
pair<bool, int> isBalanceTreeFast(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> leftP = isBalanceTreeFast(root->left);
    pair<bool, int> rightP = isBalanceTreeFast(root->right);
    bool leftAns = leftP.first;
    bool rightAns = rightP.first;
    bool diff = abs(leftP.second - rightP.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(leftP.second, rightP.second) + 1;
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    bool compaNode = root1->data == root2->data;
    if (left && right && compaNode)
    {
        return true;
    }
    else
    {
        return false;
    }
}
pair<bool, int> fastSumOfTree(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> left = fastSumOfTree(root->left);
    pair<bool, int> right = fastSumOfTree(root->right);
    bool diff = root->data == (left.second + right.second);
    bool op1 = left.first;
    bool op2 = right.first;
    pair<bool, int> ans;
    if (diff && op1 && op2)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool sumTree(node *root)
{
    return fastSumOfTree(root).first;
}
void solveSumLong(node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxSum = sum;
            maxLen = len;
        }
        if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solveSumLong(root->left, sum, maxSum, len + 1, maxLen);
    solveSumLong(root->right, sum, maxSum, len + 1, maxLen);
}
int sumOfLongestPath(node *root)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int len = 0;
    int maxLen = 0;
    solveSumLong(root, sum, maxSum, len, maxLen);
    return maxSum;
}
node *leastCommonAncestor(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftAns = leastCommonAncestor(root->left, n1, n2);
    node *rightAns = leastCommonAncestor(root->right, n1, n2);
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    if (leftAns == NULL && right != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}
// k sum problem find totol no of path whose sum is equal to k
void solveKsum(node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    solveKsum(root->left, k, count, path);
    solveKsum(root->right, k, count, path);
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
            break;
        }
    }
    path.pop_back();
}
int kSumProblem(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solveKsum(root, k, count, path);
    return count;
}
// find ktn ancesor of given node
node *solveKthAncestor(node *root, int &k, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    node *leftAns = solveKthAncestor(root->left, k, target);
    node *rightAns = solveKthAncestor(root->right, k, target);
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        else
        {
            return leftAns;
        }
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        else{
            return rightAns;
        }
    }
    return NULL;
}
int kthAncestor(node *root, int k, int target)
{
    node * ans=solveKthAncestor(root,k,target);
    if(ans==NULL || ans->data==target)
    {
        return -1;
    }
    return ans->data;
}
int main()
{
    //    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //   3 1 -1 -1 2 -1 -1
    node *root = NULL;
    root = buildTree(root);
    // node *root1 = NULL;
    // root1 = buildTree(root1);
    // levelOrderTraversal(root);
    // inorder(root);
    // preorder(root);

    //  postOrder(root);
    // cout << "Height of tree   :  " << height(root) << endl;
    // cout << "Diameter of tree :  "<< diameter(root)<< endl;
    // cout<< "Ans diameter   :    " << fastDiameter(root).first<<endl;
    // cout << "Is a blance tree : " << isBalanceTree(root) << endl;
    // cout << "is fast balnace  : " << isBalanceTreeFast(root).first << endl;

    // cout << "Is identical tree     : " << isIdentical(root, root1);
    // cout << "Sum of tree node    :   "  << sumTree(root);
    // cout << "Sum of max path    :    " << sumOfLongestPath(root);
    // cout << "Least Common Ancestor   :   " << leastCommonAncestor(root, 7, 11)->data << endl;
    // cout << "Total path whose sum is equal to K  :   " << kSumProblem(root, 5)<<endl;
    cout <<"The Kth ancestor of k is :    " << kthAncestor(root,2,7)<<endl;
    return 0;
}