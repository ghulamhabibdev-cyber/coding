#include <bits/stdc++.h>
using namespace std;
class triNode
{
public:
    char data;
    bool isTerminal;
    triNode *children[26];
    int childCount;
    triNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};
class dictionary
{
private:
    void insertUtil(triNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        triNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new triNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    bool searchUtil(triNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        triNode *child;
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
    void delelteUtil(triNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        triNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
        delelteUtil(child, word.substr(1));
    }
    bool searchPrefixUtil(triNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'a';
        triNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchPrefixUtil(child, word.substr(1));
    }

public:
    triNode *root;
    dictionary()
    {
        root = new triNode('\0');
    }
    // insert word
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    // search word
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
    // delete word
    void deleteWord(string word)
    {
        delelteUtil(root, word);
    }

    // search prefix
    bool searchPrefix(string word)
    {
        return searchPrefixUtil(root, word);
    }
    void findLongestPrefix(string &word, string &prefix)
    {

        for (int i = 0; i <word.length(); i++)
        {
            char ch = word[i];
            cout<<"Char is : "<< ch<<endl;
            if (root->childCount == 1)
            {

                prefix.push_back(ch);
                cout<<"Prefix  :  "<<endl;
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if (root->isTerminal)
            {
                break;
            }
        }
    }

    // return prefix
};
string longestPrefix(vector<string> words, int n)
{
    dictionary *d=new dictionary() ;
    for (int i = 0; i < n; i++)
    {
        d->insertWord(words[i]);
    }
    string prefix = "";
    cout<<"Entering in function \n";
    d->findLongestPrefix(words[0], prefix);
    return prefix;
}
int main()
{

    // dictionary *d = new dictionary();
    // d->insertWord("HABIB");
    // d->insertWord("AT");
    // d->insertWord("ARE");
    // d->insertWord("ARMY");
    // d->insertWord("ARM");
    // d->insertWord("ARDENO");
    // d->insertWord("ARED");
    // d->deleteWord("ARE");
    // // d->searchWord()
    // cout << "Pressent or not :   " << (d->searchWord("ARE") ? "YES" : "NO") << endl;
    // cout << "Pressent or not :   " << (d->searchWord("ARM") ? "YES" : "NO") << endl;
    // cout << "check prefix      :   " << d->searchPrefix("AQR") << endl;
    vector<string> v;
    v.push_back("coder");
    v.push_back("codet");
    v.push_back("codex");
    v.push_back("codes");
    cout << "Longest Prefix  :   " << longestPrefix(v, 4);
    return 0;
}