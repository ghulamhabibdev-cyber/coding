#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;
class node
{
public:
    node *next;
    node *prev;
    string data;
    node(string data)
    {
        this->next = prev = NULL;
        this->data = data;
    }
};
class TextEditor
{
    node * head;
    node * tail;
    int nodeCount;
public:
    TextEditor()
    {
    }

    void addText(string text)
    {
    }

    int deleteText(int k)
    {
    }

    string cursorLeft(int k)
    {
    }

    string cursorRight(int k)
    {
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main()
{

    return 0;
}