#include <iostream>
#include <queue>
using namespace std;

class heapNode
{
public:
    heapNode *left;
    heapNode *right;
    heapNode *parent;
    int value;
    heapNode(int val)
    {
        this->left = right = parent = 0;
        value = val;
    }
};
class maxHeap
{
    heapNode *rootNode;

public:
    maxHeap()
    {
        this->rootNode = NULL;
    }
    void bubbleUp(heapNode *node)
    {
        while (node->parent != nullptr && node->value > node->parent->value)
        {
            swap(node->parent->value, node->value);
            node = node->parent;
        }
    }
    void bubbleDown(heapNode *root)
    {
        while (root != NULL)
        {
            heapNode *maxNode = root;
            if (root->left != NULL && root->left->value > maxNode->value)
            {
                maxNode = root->left;
            }
            if (root->right != NULL && root->right->value > maxNode->value)
            {
                maxNode = root->right;
            }
            if (maxNode == root)
            {
                break;
            }
            swap(root->value, maxNode->value);
            root = maxNode;
        }
    }
    void addElement(int val)
    {
        heapNode *newNode = new heapNode(val);
        if (rootNode == 0)
        {
            rootNode = newNode;
            return;
        }
        queue<heapNode *> q;
        q.push(rootNode);
        while (!q.empty())
        {
            heapNode *curr = q.front();
            q.pop();
            if (curr->left == NULL)
            {
                curr->left = newNode;
                newNode->parent = curr;
                bubbleUp(newNode);
                return;
            }
            else
            {
                q.push(curr->left);
            }
            if (curr->right == NULL)
            {
                curr->right = newNode;
                newNode->parent = curr;
                bubbleUp(newNode);
                return;
            }
            else
            {
                q.push(curr->right);
            }
        }
    }
    void printHeap()
    {
        if (rootNode == 0)
        {
            return;
        }
        queue<heapNode *> q;
        q.push(rootNode);
        while (!q.empty())
        {
            heapNode *curr = q.front();
            q.pop();

            cout << curr->value << " ";
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
        cout << endl;
    }
    void deleteRoot()
    {
        if (rootNode == NULL)
        {
            return;
        }
        queue<heapNode *> q;
        q.push(rootNode);
        heapNode *lastNode = NULL;
        while (!q.empty())
        {
            lastNode = q.front();
            q.pop();
            if (lastNode->left)
            {
                q.push(lastNode->left);
            }
            if (lastNode->right)
            {
                q.push(lastNode->right);
            }
        }
        rootNode->value = lastNode->value;
        if (lastNode->parent != NULL)
        {
            if (lastNode->parent->left == lastNode)
            {
                lastNode->parent->left = NULL;
            }
            else
            {
                lastNode->parent->right = NULL;
            }
        }
        delete lastNode;
        bubbleDown(rootNode);
    }
};
int main()
{
    maxHeap hp;
    hp.addElement(100);
    hp.addElement(40);
    hp.addElement(50);
    hp.addElement(5450);
    hp.addElement(4430);
    hp.addElement(4430);
    hp.addElement(44330);
    hp.addElement(4023);
    hp.addElement(430);

    hp.printHeap();
    hp.deleteRoot();
    hp.printHeap();
    hp.deleteRoot();
    hp.deleteRoot();
    hp.printHeap();

    return 0;
}