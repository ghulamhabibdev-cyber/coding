// #include <bits/stdc++.h>
// using namespace std;
// class a
// {
//     public:

// };
// int main()
// {

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// class a
// {
//     public:

// };
// int main()
// {

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
// template <typename T>
// class graph
// {
// public:
//     unordered_map<T, list<T>> adj;
//     void addEdges(T u, T v, bool direction)
//     {
//         adj[u].push_back(v);
//         if (direction == 0)
//         {
//             adj[v].push_back(u);
//         }
//     }
//     void printAdjacList()
//     {
//         for (auto node : adj)
//         {
//             cout << node.first << "->";
//             for (auto edges : node.second)
//             {
//                 cout << edges << ", ";
//             }
//             cout << endl;
//         }
//     }
// };
// void prepareList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges)
// {
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }
// }
// void bfs(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges, unordered_map<int, bool> &visited, vector<int> &ans, int node)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = 1;
//     while (!q.empty())
//     {
//         int frontNode = q.front();
//         q.pop();

//         ans.push_back(frontNode);
//         for (auto i : adjList[frontNode])
//         {
//             if (!visited[i])
//             {
//                 q.push(i);
//                 visited[i] = 1;
//             }
//         }
//     }
// }
// vector<int> BFS(int vertex, vector<pair<int, int>> edges)
// {
//     // we need adjaceylist
//     unordered_map<int, list<int>> adjList;
//     // prepare adjacentList
//     prepareList(adjList, edges);

//     // we need vector of int to store ans;
//     vector<int> ans;
//     // we need visited vector
//     unordered_map<int, bool> visited;
//     ;

//     for (auto p : adjList)
//     {
//         int val = p.first;
//         if (!visited[val])
//         {
//             bfs(adjList, edges, visited, ans, val);
//         }
//     }
//     return ans;
// }
// // cycle detectin in graph using dfs
// bool chcecCycle(int node, unordered_map<int, list<int>> &adjacentList, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisisted)
// {
//     visited[node] = true;
//     dfsVisisted[node] = true;
//     for (auto neigh : adjacentList[node])
//     {
//         if (!visited[neigh])
//         {
//             bool fond = chcecCycle(neigh, adjacentList, visited, dfsVisisted);
//             if (fond)
//             {
//                 return true;
//             }
//         }
//         else if (dfsVisisted[neigh])
//         {
//             return true;
//         }
//     }
//     dfsVisisted[node] = false;
//     return false;
// }
// bool detctCycleDirectedGraph(int n, vector<pair<int, int>> &edges)
// {
//     // maken adjecey list that show which node is connected to which node
//     unordered_map<int, list<int>> adjacentList;

//     for (auto node : edges)
//     {
//         int u = node.first;
//         int v = node.second;
//         adjacentList[u].push_back(v);
//         adjacentList[v].push_back(u);
//     }
//     unordered_map<int, bool> visited;
//     unordered_map<int, bool> dfsVisisted;
//     for (auto data : adjacentList)
//     {
//         int node = data.first;
//         if (!visited[node])
//         {
//             if (chcecCycle(node, adjacentList, visited, dfsVisisted))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// // #->Topological sort
// void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adList)
// {
//     visited[node]=true;
//     for(auto neigh:adList[node])
//     {
//         if(!visited[neigh])
//         {
//             topoSort(neigh,visited,s,adList);
//         }
//     }
//     s.push(node);
// }
// vector<int> topoLogicalSort(vector<vector<int>> edges, int v, int e)
// {
//     // make adjacency list for given edges
//     unordered_map<int, list<int>> adjList;
//     for (int i = 0; i < e; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adjList[u].push_back(v);
//     }
//     unordered_map<int, bool> visited;
//     stack<int>s;

//     for (int i = 0; i < v; i++)
//     {
//         if (!visited[i])
//         {
//             topoSort(i,visited,s,adjList);
//         }
//     }
//     vector<int>result;
//     while(!s.empty())
//     {
//         result.push_back(s.top());
//         s.pop();
//     }
//     return result;
// }
// //topological sort using kahn's alogrythm
// vector<int>topoSortUsingKahnsAlgo(vector<vector<int>>edges,int v,int e)
// {
//     //#-> make adjacetlist of given edges;
//     unordered_map<int,list<int>>adList;
//     for(int i=0;i<e;i++)
//     {
//         int u=edges[i][0];
//         int v=edges[i][1];
//         adList[u].push_back(v);
//     }
//     //make indgree list or vec
//     vector<int>indegree(v);
//     for(auto i:adList)
//     {
//         for(auto j:i.second)
//         {
//             indegree[j]++;
//         }
//     }
//     queue<int>q;
//     for(int i=0;i<v;i++)
//     {
//         if(indegree[i]==0)
//         {
//             q.push(i);
//         }
//     }
//     vector<int> ans;// making vecor to store toplosgical sorted orderans
//     while(!q.empty())
//     {
//         int front=q.front();
//         q.pop();
//         ans.push_back(front);
//         for(auto neigh:adList[front])
//         {
//             indegree[neigh]--;
//             if(indegree[neigh]==0)
//             {
//                 q.push(neigh);
//             }

//         }

//     }
//     return ans;
// }

// ===============================================================================TreeSection===================================================
class tree
{
public:
    int data;
    tree *right;
    tree *left;
    tree(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};
tree *builTree(tree *root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new tree(data);
    cout << "Enter data for left : " << data << endl;
    root->left = builTree(root->left);
    cout << "Enter data for right : " << data << endl;
    root->right = builTree(root->right);

    return root;
}
tree *symmetricSolver(tree *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return NULL;
    }
    tree *leftAns = symmetricSolver(root->left, ans);
    tree *rightAns = symmetricSolver(root->right, ans);
    if (leftAns == NULL && rightAns == NULL)
    {
        ans.push_back(root->data);
        return root;
    }
    if (leftAns != NULL && rightAns == NULL)
    {

        ans.push_back(root->data);
        return root;
    }
    if (leftAns == NULL && rightAns != NULL)
    {

        ans.push_back(rightAns->data);
        return rightAns;
    }
    if (leftAns != NULL && rightAns != NULL)
    {

        ans.push_back(root->data);
        return root;
    }
}
// bool printData(tree * root)
// {
// }
// bool isSymmetric(tree *root)
// {

//     vector<int> ans;
//     symmetricSolver(root, ans);
//     int i = 0;
//     int j = ans.size() - 1;
//     for (int k = 0; k < ans.size(); k++)
//     {
//         cout << ans[k] << " ";
//     }
//     cout << endl;
//     while (i < j)
//     {
//         if (ans[i] != ans[j])
//         {
//             return false;
//         }
//         i++;
//         j--;
//     }
//     return true;

//     cout << endl;
// }
void levelOrderTraversal(tree *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    queue<tree *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        tree *top = q.front();
        q.pop();
        if (top == NULL)
        {
            // ans.push_back(0);
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            // cout << top->data << " ";
            ans.push_back(top->data);
            if (top->left)
            {
                q.push(top->left);
            }
            else
            {
                ans.push_back(0);
            }
            if (top->right)
            {
                q.push(top->right);
            }
            else
            {
                ans.push_back(0);
            }
        }
    }
}
void inorderTraversal(tree *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main()
{
    return 0;
}
