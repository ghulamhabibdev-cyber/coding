#include<iostream>
#include<queue>
using namespace std;

class HeapNode {
    public:
    int value;
    HeapNode* leftChild;
    HeapNode* rightChild;
    HeapNode* parentNode;
    
    HeapNode(int val) {
        value = val;
        leftChild = rightChild = parentNode = NULL;
    }
};

class MinHeap {
    public:
    HeapNode* rootNode;
    
    MinHeap() {
        rootNode = NULL;
    }
    
    void addElement(int val) {
        HeapNode* newNode = new HeapNode(val);
        
        if(!rootNode) {
            rootNode = newNode;
            return;
        }
        
        queue<HeapNode*> nodeQueue;
        nodeQueue.push(rootNode);
        
        while(!nodeQueue.empty()) {
            HeapNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            if(!currentNode->leftChild) {
                currentNode->leftChild = newNode;
                newNode->parentNode = currentNode;
                bubbleUp(newNode);
                return;
            }
            else {
                nodeQueue.push(currentNode->leftChild);
            }
            
            if(!currentNode->rightChild) {
                currentNode->rightChild = newNode;
                newNode->parentNode = currentNode;
                bubbleUp(newNode);
                return;
            }
            else {
                nodeQueue.push(currentNode->rightChild);
            }
        }
    }
    
    void bubbleUp(HeapNode* node) {
        while(node->parentNode != NULL && node->value < node->parentNode->value) {
            swap(node->value, node->parentNode->value);
            node = node->parentNode;
        }
    }
    
    void removeMin() {
        if(rootNode == NULL) return;
        
        queue<HeapNode*> nodeQueue;
        nodeQueue.push(rootNode);
        HeapNode* lastNode = NULL;
        
        while(!nodeQueue.empty()) {
            lastNode = nodeQueue.front();
            nodeQueue.pop();
            
            if(lastNode->leftChild) nodeQueue.push(lastNode->leftChild);
            if(lastNode->rightChild) nodeQueue.push(lastNode->rightChild);
        }
        
        rootNode->value = lastNode->value;
        
        if(lastNode->parentNode != NULL) {
            if(lastNode->parentNode->leftChild == lastNode)
                lastNode->parentNode->leftChild = NULL;
            else
                lastNode->parentNode->rightChild = NULL;
        }
        
        delete lastNode;
        bubbleDown(rootNode);
    }
    
    void bubbleDown(HeapNode* node) {
        while(node != NULL) {
            HeapNode* minNode = node;

            if(node->leftChild != NULL && node->leftChild->value < minNode->value) {
                minNode = node->leftChild;
            }
            
            if(node->rightChild != NULL && node->rightChild->value < minNode->value) {
                minNode = node->rightChild;
            }
            
            if(minNode == node)
                break;
                
            swap(node->value, minNode->value);
            node = minNode;
        }
    }
    
    void displayHeap() {
        if(rootNode == NULL) {
            cout << "Heap is empty";
            return;
        }
        
        queue<HeapNode*> nodeQueue;
        nodeQueue.push(rootNode);
        
        while(!nodeQueue.empty()) {
            HeapNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
            
            cout << currentNode->value << " ";
            
            if(currentNode->leftChild != NULL)
                nodeQueue.push(currentNode->leftChild);
            if(currentNode->rightChild != NULL)
                nodeQueue.push(currentNode->rightChild);
        }
    }
};

int main() {
    MinHeap heap;
    heap.addElement(40);
    heap.addElement(4);
    heap.addElement(20);
    heap.addElement(1);
    
    heap.displayHeap();
    
    cout << "\nAfter Deleting: ";
    heap.removeMin();
    heap.displayHeap();
}