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
int heightOfTree(node * root)
{
   if(root==NULL)
   {
    return 0;
   } 
   int left=heightOfTree(root->left);
   int right=heightOfTree(root->right);
   return left+right+1;
    

}
node *buildTree(node *root)
{
    cout << "Enter the data for node\n";
    int data;
    cin >> data;
    root = new node(data);
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
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    vector<int>sym;
    sym.push_back(root->data);
    while (!q.empty())
    {
        bool flag=true;
        int i=0;
        int j=sym.size()-1;
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            while(i<j)
            {
                if(sym[i]!=sym[j])
                {
                    flag=false;
                    break;
                }
                i++;
                j--;

            }
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
        if(flag==false)
        {
            break;
        }
    }
}
void inorderTraversal(node *root)
{
    //LNR
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void PreorderTraversal(node *root)
{
    //NLR

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void postOrder(node *root)
{
    //LRN
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void  bulidFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root \n";
    int data;
    cin >> data;
    
    root=new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout<<"Enter data for left of : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1)
        {
            temp->left=new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter data for right of : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1)
        {
            temp->right=new node(rightData);
            q.push(temp->right);
        }
        
    }
}
int main()
{
    node *root = NULL;
    // root = buildTree(root);
    // level order travesel 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "print data \n";
    // levelOrderTraversal(root);
    // inorderTraversal(root);
    // PreorderTraversal(root);
    // postOrder(root);
    bulidFromLevelOrder(root);
    levelOrderTraversal(root);
    cout << "don";
    return 0;
}