#include <bits/stdc++.h>
using namespace std;
class trieNode
{
public:
    char data;
    bool isTeminal;
    trieNode *children[26];
    trieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTeminal = false;
    }
};
class trie
{
public:
    trieNode *root;
    trie()
    {
        root = new trieNode('\0');
    }
    void insertUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTeminal = true;
            return;
        }
        int index = word[0] - 'A';
        trieNode *child;
        if (root->children[index] != NULL)
        {
            child= root->children[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTeminal;
        }
        int index = word[0] - 'A';
        trieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
    bool removUtils(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTeminal = false;
            return true;
        }
        int index = word[0] - 'A';
        trieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return removUtils(child, word.substr(1));
    }
    bool removeWord(string word)
    {
        return removUtils(root, word);
    }
};

int main()
{
    trie *t = new trie();
    t->insertWord("HABIB");
    t->insertWord("HABIBI");

    cout << "Present or not: " << (t->searchWord("HABIB") ? "Yes" : "No") << endl;
    cout << "Present or not: " << (t->searchWord("ALI") ? "Yes" : "No") << endl;
    cout << "Present or not: " << (t->searchWord("HABIBI") ? "Yes" : "No") << endl;
    cout << "Present or not: " << (t->removeWord("HABIBI") ? "reomve" : "error") << endl;
    cout << "Present or not: " << (t->searchWord("HABIBI") ? "Yes" : "No") << endl;

    return 0;
}