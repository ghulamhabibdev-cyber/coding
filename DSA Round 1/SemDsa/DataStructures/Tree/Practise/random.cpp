#include <iostream>
#include <queue>
using namespace std;

class Node
{
private:
    int data;
    Node *leftNode;
    Node *rightNode;

public:
    Node(int num)
    {
        this->data = num;
        leftNode = NULL;
        rightNode = NULL;
    }
    Node()
    {
        this->data = 0;
        leftNode = NULL;
        rightNode = NULL;
    }
    void setData(int num)
    {
        this->data = num;
    }
    int getData()
    {
        return data;
    }
    void setLeft(Node *node)
    {
        this->leftNode = node;
    }
    void setRight(Node *node)
    {
        this->rightNode = node;
    }
    Node *getLeft()
    {
        return leftNode;
    }
    Node *getRight()
    {
        return rightNode;
    }
};
Node *buildBST(Node *root, int data)
{
    if (!root)
    {
        return new Node(data);
    }
    if (data < root->getData())
    {
        root->setLeft(buildBST(root->getLeft(), data));
    }
    if (data > root->getData())
    {
        root->setRight(buildBST(root->getRight(), data));
    }
    return root;
}
void preOrderTravaersal(Node *root)
{
    if (root)
    {
        cout << root->getData() << " ";
        preOrderTravaersal(root->getLeft());
        preOrderTravaersal(root->getRight());
    }
}
void inOrderTraversal(Node *root)
{
    if (root)
    {

        inOrderTraversal(root->getLeft());
        cout << root->getData() << " ";
        inOrderTraversal(root->getRight());
    }
}
void postOrderTraversal(Node *root)
{
    if (root)
    {
        postOrderTraversal(root->getLeft());
        postOrderTraversal(root->getRight());
        cout << root->getData() << " ";
    }
}
void leverOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> levelQueue;
    levelQueue.push(root);
    levelQueue.push(NULL);
    while (!levelQueue.empty())
    {
        Node *currLeverNode = levelQueue.front();
        levelQueue.pop();
        if (currLeverNode == NULL)
        {
            cout << endl;
            if (!levelQueue.empty())
            {
                levelQueue.push(NULL);
            }
        }
        else
        {
            cout << currLeverNode->getData() << " ";
            if (currLeverNode->getLeft())
            {
                levelQueue.push(currLeverNode->getLeft());
            }
            if (currLeverNode->getRight())
            {
                levelQueue.push(currLeverNode->getRight());
            }
        }
    }
}
int countNoOfNode(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int noLeftSubTreeNodes = countNoOfNode(root->getLeft());
    int noRightSubTreeNodes = countNoOfNode(root->getRight());
    int noCurrTreeNodes = 1 + noLeftSubTreeNodes + noRightSubTreeNodes;
    return noCurrTreeNodes;
}
int getHeight(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int leftSubTreeHeight = getHeight(root->getLeft());
    int rightSubTreeHeight = getHeight(root->getRight());
    int currTreeHeight = 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    return currTreeHeight;
}
int findMinNode(Node *root)
{
    if (!root)
    {
        return INT_MAX;
    }
    int leftMinNodeData = findMinNode(root->getLeft());
    int rightMinNodeData = findMinNode(root->getRight());
    int rootData = root->getData();
    if (leftMinNodeData < rootData && leftMinNodeData < rightMinNodeData)
    {
        return leftMinNodeData;
    }
    else if (rightMinNodeData < rootData && rightMinNodeData < leftMinNodeData)
    {
        return rightMinNodeData;
    }
    else
    {
        return rootData;
    }
}
int findMaxNode(Node *root)
{
    if (!root)
    {
        return INT_MIN;
    }
    int leftMinNodeData = findMaxNode(root->getLeft());
    int rightMinNodeData = findMaxNode(root->getRight());
    int rootData = root->getData();
    if (leftMinNodeData > rootData && leftMinNodeData > rightMinNodeData)
    {
        return leftMinNodeData;
    }
    else if (rightMinNodeData > rootData && rightMinNodeData > leftMinNodeData)
    {
        return rightMinNodeData;
    }
    else
    {
        return rootData;
    }
}
Node * findLastRight(Node * root)
{
    if(root->getRight()==NULL)
    {
        return root;
    }
    return findLastRight(root->getRight());
}
Node * deletionHelper(Node * root)
{
    if(root->getRight()==NULL)
    {
        return root->getLeft();
    }
    if(root->getLeft()==NULL)
    {
        return root->getRight();
    }
    Node * rootRightChild=root->getRight();
    Node * lastChild=findLastRight(root->getLeft());
    lastChild->setRight(rootRightChild);
    return root->getLeft();
}
Node * deleteNode(Node *root,int key)
{
    if(!root)
    {
        return NULL;
    }
    if(key<root->getData())
    {
       root->setLeft(deleteNode(root->getLeft(), key));
        return root;
    }
    if(key>root->getData())
    {
        root->setRight(deleteNode(root->getRight(),key));
        return root;
    }
    else{
      return deletionHelper(root);
    }
}
int globalVariable = 1000;
int main()
{
    Node *root = NULL;
    cout << "Enter Root Node Data \n";
    cout << "Enter -1 To Exit \n";
    int nodeData = 0;
    while (nodeData != -1)
    {
        cout << "Enter Node Data \n";
        cin >> nodeData;
        if (nodeData == -1)
        {
            break;
        }
        root = buildBST(root, nodeData);
    }
    cout << "inOrderTraversal\n";
    inOrderTraversal(root);
    cout << endl;
    //     cout<<"PreOrderTraversal \n";
    //     preOrderTravaersal(root);
    //     cout<<endl;

    //     cout<<endl;
    //     cout<<"PostOrderTraversal\n";
    //     postOrderTraversal(root);
    //     cout<<endl;
    //     cout<<"Level Order Traveral \n";
    //     leverOrderTraversal(root);
    //     cout<<endl;
    //     cout<<"Total No Of Node \n";
    //    cout<< countNoOfNode(root)<<endl;
    //    cout<<"Prenting the Height to Tree \n";
    //    cout<<getHeight(root)<<endl;
    //    cout<<"Finding The Minimum Of Tree \n";
    //    cout<<findMinNode(root)<<endl;
    //    cout<<"Max Node Of Tree \n";
    //    cout<<findMaxNode(root)<<endl;
    //    cout<<"I am Gloabal Vairabale "<<globalVariable<<endl;
    int key;
    cout<<"Enter delete Node data \n";
    cin>>key;
    root = deleteNode(root, key);
    inOrderTraversal(root);

    return 0;
}