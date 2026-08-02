#include <iostream>
#include<stack>
#include<queue>
using namespace std;

class Node
{
    char exp;
    Node *left;
    Node *right;

public:
    Node()
    {
        this->exp = ' ';
        this->left = NULL;
        this->right = NULL;
    }
     Node(char exp)
    {
        this->exp = exp;
        this->left = NULL;
        this->right = NULL;
    }
    char getExp()
    {
        return exp;
    }
    void setExp(char ch)
    {
        this->exp;
    }
    Node * getLeft()
    {
        return left;
    }
    Node * getRight()
    {
        return right;
    }
    void setLeft(Node * node)
    {
        this->left=node;
    }
    void setRight(Node * node)
    {
        this->right=node;
    }
};
Node* buildExpressTree(string str)
{
    stack<Node*>st;
    int len=str.length();
    int i=0;
    while(i!=len)
    {
        char ch=str[i];
        i++;
        if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='%'&&ch!='^')
        {
            Node * node=new Node(ch);
            st.push(node);
        }
        else{
             Node * node=new Node(ch);
             Node * second=st.top();
             st.pop();
             Node * first=st.top();
             st.pop();
            node->setLeft(first);
            node->setRight(second);
            st.push(node);
        }
    }
    return st.top();
}
void preOrder(Node * root)
{
    if(root)
    {
        cout<<root->getExp()<<" ";
        preOrder(root->getLeft());
        preOrder(root->getRight());
    }
}
void levelOrderTraversal(Node * root)
{
    if(root)
    {
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp=q.front();
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
                cout<<temp->getExp()<<" ";
                if(temp->getLeft())
                {
                    q.push(temp->getLeft());
                }
                if(temp->getRight())
                {
                    q.push(temp->getRight());
                }
            }
            /* code */
        }
        
        
    }
}
int main()
{
    Node * root=NULL;
    string str="ab+cde**+";
  root=  buildExpressTree(str);
  levelOrderTraversal(root);


    return 0;
}