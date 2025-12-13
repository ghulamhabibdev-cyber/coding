#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = data;
        height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};
int getHeight(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int getBalacneFactor(Node * root )
{
    if(!root)
        return 0;
    return getHeight(root->left)-getHeight(root->right);
}  
Node * rightRotation(Node * root)
{
    Node * child=root->left;
    Node * childRight=child->right;
    child->right=root;
    root->left=childRight;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node * leftRotataion(Node * root)
{
    Node * child=root->right;
    Node * childLeft=child->left;
    child->left=root;
    root->right=childLeft;
    root->height=1+max(getHeight(root->left),getHeight(root->right));
   child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}
Node * insert(Node * root,int data)
{
    if(!root)
    {
        return new Node(data);
    }
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    else{
        return root;
    }
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    int balance=getBalacneFactor(root);
    // left left case:
    if(balance>1 && data<root->left->data)
    {
        return rightRotation(root);
    }
    // right right case: 
    else if(balance< -1&&data>root->right->data)
    {
        return leftRotataion(root);
    }
    // left right Case:
    else if(balance>1 &&data>root->left->data)
    {
         root->left = leftRotataion(root->left);
        return rightRotation(root);
    }
    // right left 
    else if(balance<-1&&data<root->right->data)
    {
            root->right=rightRotation(root->right);
            return leftRotataion(root);
    }
    else{
        
        return root;
    }

}
int main()
{

    return 0;
}