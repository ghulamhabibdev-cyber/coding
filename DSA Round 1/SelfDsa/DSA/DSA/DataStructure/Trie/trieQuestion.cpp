#include <bits/stdc++.h>
using namespace std;
class a
{
public:
};
string longestCommonPrefix(vector<string> arr, int n)
{
    string ans = "";
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;
        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}
class trieNode
{
public:
    char data;
    bool isTeminal;
    trieNode *children[26];
    int childCount;
    trieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTeminal = false;
        childCount = 0;
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
        int index = word[0] - 'a';
        trieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trieNode(word[0]);
            root->childCount++;
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
        int index = word[0] - 'a';
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
        int index = word[0] - 'a';
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
    // void longestPrefix(string str, string &ans)
    // {
    //     for (int i = 0; i < str.length(); i++)
    //     {
    //         char ch = str[i];
    //         if (root->childCount == 1)
    //         {
    //             ans.push_back(ch);
    //             int index = ch - 'a';
    //             root = root->children[index];
    //         }
    //         else
    //         {
    //             break;
    //         }
    //         if (root->isTeminal)
    //         {
    //             break;
    //         }
    //     }
    // }
    // void printSuggest(trieNode *curr, vector<string> &temp, string prefix)
    // {
    //     if (curr->isTeminal)
    //     {
    //         temp.push_back(prefix);
    //     }
    //     for (char ch = 'a'; ch <= 'z'; ch++)
    //     {
    //         trieNode *next = curr->children[ch - 'a'];
    //         if (next != NULL)
    //         {
            
    //             prefix.push_back(ch);
    //             printSuggest(next, temp, prefix);
    //             prefix.pop_back();
    //         }
    //     }
    // }
    // vector<vector<string>> getSuggestion(string query)
    // {
    //     trieNode *prev = root;
    //     vector<vector<string>> output;
    //     string prefix = "";
    //     for (int i = 0; i < query.length(); i++)
    //     {
    //         char last = query[i];
    //         prefix.push_back(last);
    //         trieNode *curr = prev->children[last - 'a'];
    //         if (curr == NULL)
    //         {
    //             break;
    //         }
    //         vector<string> temp;
    //         printSuggest(curr, temp, prefix);
    //         output.push_back(temp);
    //         temp.clear();
    //         prev = curr;
    //     }
    //     return output;
    // }
};
// string longestPrefix(vector<string> arr, int n)
// {

//     trie *t = new trie();
//     for (int i = 0; i < n; i++)
//     {
//         t->insertWord(arr[i]);
//     }
//     string ans = "";
//     t->longestPrefix(arr[0], ans);
//     return ans;
// }
// vector<vector<string>> phoneDirectory(vector<string> contacList, string query)
// {
//     trie *t = new trie();
//     for (int i = 0; i < contacList.size(); i++)
//     {
//         t->insertWord(contacList[i]);
//     }
//     return t->getSuggestion(query);
// }

int main()
{

    vector<string> v;
    v.push_back("coding");
    v.push_back("code");

    // v.push_back("coder");
    // v.push_back("codet");

    // v.push_back("codex");
    // v.push_back("codes");
    // cout<<longestCommonPrefix(v,2)<<endl;
    // cout << longestPrefix(v, 2) << endl;
    // phoneDirectory(v, "co");
    // vector<vector<string>> ans = phoneDirectory(v, "co");
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans.size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //         {
    //         }
    //     }
    // }
    return 0;
}