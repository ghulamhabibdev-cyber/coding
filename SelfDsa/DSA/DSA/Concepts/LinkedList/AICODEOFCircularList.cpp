#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~node() {
        cout << "Deleting node with value: " << data << endl;
        this->next = NULL; // prevent recursive deletion in circular list
    }
};

void insertNode(node*& tail, int element, int d) {
    if (tail == NULL) {
        node* temp = new node(d);
        tail = temp;
        temp->next = temp;
    } else {
        node* curr = tail;
        bool found = false;
        do {
            if (curr->data == element) {
                found = true;
                break;
            }
            curr = curr->next;
        } while (curr != tail);

        if (!found) {
            cout << "Element " << element << " not found!" << endl;
            return;
        }

        node* temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;

        // Optional: update tail if inserting after tail
        if (curr == tail) {
            tail = temp;
        }
    }
}

void printNode(node* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void deleteNode(node*& tail, int element) {
    if (tail == NULL) {
        cout << "Empty List..........\n";
        return;
    }

    node* prev = tail;
    node* curr = prev->next;
    bool found = false;

    do {
        if (curr->data == element) {
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    if (!found) {
        cout << "Element " << element << " not found!" << endl;
        return;
    }

    if (curr == prev) {
        // Only one node in list
        tail = NULL;
    } else {
        prev->next = curr->next;
        if (curr == tail) {
            tail = prev;
        }
    }

    curr->next = NULL;
    delete curr;
}
int main() {
    node* tail = NULL;

    insertNode(tail, 5, 1);      // First node (special case)
    insertNode(tail, 1, 4);      // 1 -> 4
    insertNode(tail, 1, 5);      // 1 -> 5 -> 4
    insertNode(tail, 1, 100);    // 1 -> 100 -> 5 -> 4
    insertNode(tail, 1, 5);      // 1 -> 5 -> 100 -> 5 -> 4

    deleteNode(tail, 1);         // Delete node with value 1

    printNode(tail);             // Should print: 5 100 5 4

    return 0;
}
