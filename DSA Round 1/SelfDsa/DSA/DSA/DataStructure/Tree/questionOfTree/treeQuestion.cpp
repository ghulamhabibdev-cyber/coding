#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
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

// find the height of binary tree
int heightOfTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
// find the diameter of  tree
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = heightOfTree(root->left) + 1 + heightOfTree(root->right);
    int ans = max(op1, max(op2, op3));
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
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}

// is a tree is balalnce
bool isBalance(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool left = isBalance(root->left);
    bool right = isBalance(root->right);
    bool diff = abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1;
    if (left && right && diff)
    {
        return true;
    }
    return false;
}
pair<bool, int> fastIsBalanece(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<int, int> left = fastIsBalanece(root->left);
    pair<int, int> right = fastIsBalanece(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
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
// check whether two tree are identical or not
bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL && root2 != NULL)
    {
        return false;
    }
    if (root1 != NULL && root2 == NULL)
    {
        return false;
    }
    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);
    bool value = root1->data == root2->data;
    if (value && left && right)
    {
        return true;
    }
    return false;
}
// sum  trere 3 1 2 mean sum of each node is equal to left and right
pair<bool, int> fastIsSumTree(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // check for leaf node
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> leftAns = fastIsSumTree(root->left);
    pair<bool, int> rightAns = fastIsSumTree(root->right);
    bool left = leftAns.first;
    bool right = rightAns.first;
    bool cond = root->data == leftAns.second + rightAns.second;
    pair<bool, int> ans;
    if (left && right && cond)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}
bool isSum(node *root)
{
    return fastIsSumTree(root).first;
}

// find the sum of longest path
void solve(node *root, int sum, int &maxsum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxsum = sum;
        }
        if (len == maxLen)
        {
            maxsum = max(sum, maxsum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxsum, len + 1, maxLen);
    solve(root->right, sum, maxsum, len + 1, maxLen);

    // solve(root->left,sum,maxsum,len+1,maxLen);
}
int sumOfLongestRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
// lca leat common ancesstor of a nods
node *LCA(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *leftAns = LCA(root->left, n1, n2);
    node *rightAns = LCA(root->right, n1, n2);
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

// k sum path mean find total path whose sum is equal to k
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
int sumK(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solveKsum(root, k, count, path);
    return count;
}
// find k th ancestor of node give node
node *solveKAncestor(node *root, int &k, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    node *leftAns = solveKAncestor(root->left, k, target);
    node *rightAns = solveKAncestor(root->right, k, target);
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
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        else
        {
            return rightAns;
        }
    }
    return NULL;
}
int kthAncestor(node *root, int k, int target)
{
    node *ans = solveKAncestor(root, k, target);
    if (ans == NULL || ans->data == target)
    {
        return -1;
    }
    return ans->data;
}
// find max sum non adjacent node
pair<int, int> solveGetMaxSum(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> leftAns = solveGetMaxSum(root->left);
    pair<int, int> rightAns = solveGetMaxSum(root->right);
    pair<int, int> res;
    res.first = root->data + leftAns.second + rightAns.second;
    res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
    return res;
}

int getMaxSum(node *root)
{
    pair<int, int> ans = solveGetMaxSum(root);
    return max(ans.first, ans.second);
}
// build tree from inorder and preorder
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
        {
            return i;
        }
    }
    return -1;
}
void buildMaping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}
node *buildSolve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> nodeToIndex)
{
    if (index >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = pre[index++];
    node *root = new node(element);
    buildMaping(in, nodeToIndex, n);
    int position = nodeToIndex[element];

    // int position = findPosition(in, element, n);

    root->left = buildSolve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
    root->right = buildSolve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
    return root;
}
node *buildTree2(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    node *ans = buildSolve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}
// build tree from pre and post order
node *buildSolve3(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> nodeToIndex)
{
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    int element = post[index--];
    node *root = new node(element);
    buildMaping(in, nodeToIndex, n);
    int position = nodeToIndex[element];

    // int position = findPosition(in, element, n);
    root->right = buildSolve3(in, post, index, position + 1, inOrderStart, n, nodeToIndex);
    root->left = buildSolve3(in, post, index, inOrderStart, position - 1, n, nodeToIndex);
    return root;
}
node *buildTree3(int in[], int post[], int n)
{
    int postIndex = n - 1;
    map<int, int> nodeToIndex;
    node *ans = buildSolve3(in, post, postIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}
// buringin a tree find the time to butn the tree iof a target node find min time to find time

node *creatParentMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *res = NULL;
    queue<node *> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (front->data == target)
        {
            res = front;
        }
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(node *root, map<node *, node *> &nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // process the neighbouring node
            node *front = q.front();
            q.pop();
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]); // ✅ push parent
                visited[nodeToParent[front]] = 1;
            }
        }
        if (flag == 1)
        {
            ans++;
        }

        /* code */
    }
    return ans;
}
int minTime(node *root, int target)
{

    map<node *, node *> nodeToParent;
    node *targetNode = creatParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
// flatten   a tree into a linkn list using morris traversal
//  morris algo is home work

void flattenTree(node*& root) {
    node* curr = root;
    while (curr != NULL) {
        if (curr->left) {
            // find the rightmost node in left subtree
            node* pred = curr->left;
            while (pred->right) {
                pred = pred->right;
            }
            // connect right subtree to predecessor
            pred->right = curr->right;
            // move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }
        // ✅ move to the next right node
        curr = curr->right;
    }
}
//check where given bt is heap
int coountNode(node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1+coountNode(root->left)+coountNode(root->right);
    return ans;
}
bool isCBT(node * root,int index,int cnt)
{
    if(root==NULL)
    {
        return true;
    }
    if(index>=cnt)
    {
        return false;
    }
    else{
        bool left=isCBT(root->left,2*index+1,cnt);
        bool right=isCBT(root->right,2*index+2,cnt);
        return (left&&right);
    }
}
bool isMaxOrder(node *root)
{
    if(root->left==NULL&& root->right==NULL)
    {
        return true;
    }
    if(root->right==NULL)
    {
        return (root->data>root->left->data && isMaxOrder(root->left));
    }
    else{
        bool left=isMaxOrder(root->left);
        bool right=isMaxOrder(root->right);
        return (left&&right && (root->data>root->left->data && root->data>root->right->data));
    }
}
bool isHeap(node * root)
{
    int index=0;
    int totalCOunt=coountNode(root);
    if(isCBT(root,index,totalCOunt)&&isMaxOrder(root))
    {
        return true;
    }
    return false;
}


int main()
{
    //   1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 3 1 -1 -1 2 -1 -1

    node *root = NULL;
    root = buildTree(root);
    // node *root2 = NULL;
    // root2 = buildTree(root2);
    // levelOrderTraversal(root);
    // inorder(root);
    // preorder(root);

    // postOrder(root);
    // cout << "\nheigt of tree  : " << heightOfTree(root) << " ";
    // cout << endl;
    // cout << "Diameter of tree : " << diameter(root) << endl;
    // pair<int, int> diaHeight = fastDiameter(root);
    // cout << "Fast diameter   : " << diaHeight.first << endl;
    // cout << "Fast Height     : " << diaHeight.second << endl;
    cout << endl;
    // cout << "IS balane : " << isBalance(root);
    // cout << "Is blance fast : " << fastIsBalanece(root).first << " \n";
    // cout << " Is identical : " << isIdentical(root, root2) << endl;
    // cout << "is sum equal : " << isSum(root);

    // cout << sumOfLongestRootToLeafPath(root) << endl;
    // cout <<" LCA Of  : "<<LCA(root,27,11)->data<<endl;
    // levelOrderTraversal(root);
    // cout << "total path :  " << sumK(root, 5) << endl;
    // cout << " kth ancestor of : " << kthAncestor(root, 2, 7) << endl;
    // cout <<"max sum of non adjacent node : " << getMaxSum(root);

    // build tree from inorder and preorder
    // int inorder[4] = {1, 6, 8, 7}; // LNR
    // int preoder[4] = {1, 6, 7, 8}; // NLR
    // node *temp = buildTree2(inorder, preoder, 4);

    // postOrder(temp); // LRN
    // int in[8] = {4, 8, 2, 5, 1, 6, 3, 7};
    // int pos[8] = {8, 4, 5, 2, 6, 7, 3, 1};
    // node *tempy = buildTree3(in, pos, 8);
    // postOrder(tempy);
    // cout << "Mis time to burn tree :  " << minTime(root, 7);
    // flattenTree(root);
    // levelOrderTraversal(root);

    cout<<"Isheap   :   "<< isHeap(root);
    return 0;
}