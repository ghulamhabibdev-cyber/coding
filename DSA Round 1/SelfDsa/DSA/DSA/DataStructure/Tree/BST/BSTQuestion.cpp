#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertData(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = insertData(root->right, data);
    }
    else
    {
        root->left = insertData(root->left, data);
    }
    return root;
}
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertData(root, data);
        cin >> data;
        /* code */
    }
}
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
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
void inorderTraver(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraver(root->left);
    cout << root->data << " ";
    inorderTraver(root->right);
}
bool searchInBST(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (root->data > data)
    {
        return searchInBST(root->right, data);
    }
    else
    {
        return searchInBST(root->left, data);
    }
}
Node *minVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *maxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
// deletion in binary search tree
Node *deletionInBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 chil
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child case
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child case
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletionInBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = deletionInBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deletionInBST(root->right, val);
        return root;
    }
    return NULL;
}
// from this we are doing bst question
// #1 validate a bst
bool isBst(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = isBst(root->left, min, root->data);
        bool right = isBst(root->right, root->data, max);
        return (left && right);
    }
    else
    {
        return false;
    }
}
// find kth smallest element of BST
int solvekthSmall(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = solvekthSmall(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return solvekthSmall(root->right, i, k);
}
int kthSamllestElement(Node *root, int k)
{
    int i = 0;
    int ans = solvekthSmall(root, i, k);
    return ans;
}
// find predecor and succsor
pair<int, int> findPredecesorSuccesor(Node *root, int key)
{
    Node *temp = root;
    int pred = -1;
    int succ = -1;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }
    // finding predessor
    //  firts fo to left then move right right right
    Node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
        /* code */
    }
    // finding successor
    // go to left and left
    Node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
        /* code */
    }
    // makig pair to returt he ans
    pair<int, int> p = make_pair(pred, succ);
    return p;
}
// find lca if
Node *findLCAInBST(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < p && root->data < q)
    {
        return findLCAInBST(root->right, p, q);
    }
    if (root->data > p && root->data > q)
    {
        return findLCAInBST(root->left, p, q);
    }
    return root;
}
Node *findLCAInBST2(Node *root, int p, int q)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root != NULL)
    {
        if (root->data < p && root->data < q)
        {
            root = root->right;
        }
        if (root->data > p && root->data > q)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
        /* code */
    }
    return NULL;
}
// two sum in BST
void inoderVec(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inoderVec(root->left, v);
    v.push_back(root->data);
    inoderVec(root->right, v);
}
bool TwoSumBST(Node *root, int target)
{
    vector<int> v;
    inoderVec(root, v);
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
        /* code */
    }
    return false;
}
// flaten a BST into link list
// struct node {
//     int data;
//     node* left;
//     node* right;
//     node(int val) {
//         data = val;
//         left = right = NULL;
//     }
// };
//
// // Linked List Node
// struct ListNode {
//     int data;
//     ListNode* next;
//     ListNode(int val) {
//         data = val;
//         next = NULL;
//     }
// };
//
// // Helper function: Inorder traversal to build linked list
// void bstToLinkedList(node* root, ListNode*& head, ListNode*& tail) {
//     if (!root) return;
//
//     // Left subtree
//     bstToLinkedList(root->left, head, tail);
//
//     // Process current node
//     ListNode* newNode = new ListNode(root->data);
//     if (!head) {
//         head = tail = newNode;
//     } else {
//         tail->next = newNode;
//         tail = newNode;
//     }
//
//     // Right subtree
//     bstToLinkedList(root->right, head, tail);
// }
//
// // Main function
// ListNode* convertBSTtoLL(node* root) {
//     ListNode* head = NULL;
//     ListNode* tail = NULL;
//     bstToLinkedList(root, head, tail);
//     return head;
// }

Node *flattend(Node *root)
{
    vector<int> v;
    inoderVec(root, v);
    int n = v.size();
    Node *newRoot = new Node(v[0]);
    Node *curr = newRoot;
    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(v[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
// Normal BST to Balance BST
Node *inorderToBST(int s, int e, vector<int> &v)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *root = new Node(v[mid]);
    root->left = inorderToBST(s, mid - 1, v);
    root->right = inorderToBST(mid + 1, e, v);
    return root;
}
Node *balanceBST(Node *root)
{
    vector<int> v;
    inoderVec(root, v);
    return inorderToBST(0, v.size() - 1, v);
}
// preorder to bst
Node *solvePresorderToBST(vector<int> &v, int min, int max, int &i)
{
    if (i >= v.size())
    {
        return NULL;
    }
    if (v[i] < min || v[i] > max)
    {
        return NULL;
    }
    Node *root = new Node(v[i++]);
    root->left = solvePresorderToBST(v, min, root->data, i);
    root->right = solvePresorderToBST(v, root->data, max, i);
    return root;
}
Node *preoderToBST(vector<int> v)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;
    return solvePresorderToBST(v, min, max, i);
}
// merge  two bst
vector<int> mergeArray(vector<int> bst1, vector<int> bst2)
{
    vector<int> ans(bst1.size() + bst2.size());
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
        {
            ans[k++] = bst1[i];
            i++;
        }
        else
        {
            ans[k++] = bst2[j];
            j++;
        }
    }
    while (i < bst1.size())
    {
        ans[k++] = bst1[i];
        i++;
        /* code */
    }
    while (j < bst2.size())
    {
        ans[k++] = bst2[j];
        j++;
    }
    return ans;
}
void inorderToBST2(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorderToBST2(root->left, v);
    v.push_back(root->data);
    inorderToBST2(root->right, v);
}
Node *mergetTwoBst(Node *root1, Node *root2)
{
    vector<int> bst1, bst2;
    inorderToBST2(root1, bst1);
    inorderToBST2(root2, bst2);
    vector<int> mergeArr = mergeArray(bst1, bst2);
    int s = 0;
    int e = mergeArr.size() - 1;
    Node *ans = inorderToBST(s, e, mergeArr);
    return ans;
}
// largert bst in binary tree
// your task is to find largest bst in tree and reuturn its size
class info
{
public:
    int maxi;
    int mini;
    int size;
    bool isBst;
};
info solveLargestBst(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, 0, true}; // fixed order
    }

    info left = solveLargestBst(root->left, ans);
    info right = solveLargestBst(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBst && right.isBst &&
        root->data > left.maxi &&
        root->data < right.mini)
    {
        currNode.isBst = true;
        ans = max(ans, currNode.size);
    }
    else
    {
        currNode.isBst = false;
    }

    return currNode;
}

int largestBST(Node *root)
{
    int maxSize = 0;
    solveLargestBst(root, maxSize);
    return maxSize;
}

Node *buildTree()
{
    int data;
    cout << "Enter the data for node (-1 for NULL): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}
// bst to minheap
//  i solve this question in bst
void bstToHeap(Node *&root, vector<int> v, int &i)
{
    if (!root)
        return;
    root->data = v[i++];
    bstToHeap(root->left, v, i);
    bstToHeap(root->right, v, i);
}
void bstToMinHeap(Node* root, vector<int> &v) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    int i = 0;

    while (!q.empty()) {
        Node* curr = q.front(); 
        q.pop();
        
        curr->data = v[i++];  // Assign sorted values in BFS order

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main()
{
    // 10 8 2 3 21 23 11 1 -1
    // 50 60 20 10 30 40 90 60 70 80 -1
    Node *root = NULL;
    takeInput(root);
    // levelOrderTraversal(root);
    // root=deletionInBST(root,50);
    // inorderTraver(root);
    // cout<<isBst(root,INT_MIN,INT_MAX)<<endl;
    // cout << kthSamllestElement(root, 5) << endl;
    // pair<int, int> p = findPredecesorSuccesor(root, 3);
    // cout << p.first << endl;
    // cout << p.second << endl;
    // cout<<findLCAInBST2(root,3,1)->data<<endl;
    // cout<<TwoSumBST(root,110)<<endl;
    // Node * temp=flattend(root);
    // levelOrderTraversal(temp);
    // Node *temp = balanceBST(root);
    // levelOrderTraversal(temp);

    vector<int> v;
    // v.push_back(20);
    // v.push_back(10);
    // v.push_back(5);
    // v.push_back(15);
    // v.push_back(13);
    // v.push_back(35);
    // v.push_back(30);
    // v.push_back(42);

    // v.push_back(40);
    // v.push_back(10);
    // v.push_back(3);
    // v.push_back(2);
    // v.push_back(15);
    // v.push_back(14);
    // v.push_back(12);
    // v.push_back(50);
    // v.push_back(90);

    // v.push_back(40);
    // v.push_back(40);

    // Node *temp = preoderToBST(v);
    // levelOrderTraversal(temp);
    //  Node *root1 = NULL;
    // takeInput(root1);
    // Node * root2=NULL;
    //  takeInput(root2);
    // Node * ans=mergetTwoBst(root1,root2);
    // inorderTraver(ans);
    //     Node * root=NULL;
    //     root=buildTree();
    //    int ans= largestBST(root);
    //    cout<< " largest BST :  "<< ans<<endl;

    inoderVec(root, v);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "geting data " << endl;
    int i = 0;
    // bstToHeap(root, v, i);
    bstToMinHeap(root,v);
    inorderTraver(root);
    // levelOrderTraversal(root);

    cout << endl;

    return 0;
}