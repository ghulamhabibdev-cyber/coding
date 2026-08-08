class Solution
{
public:
    vector<int> FindShotestPath(vector<vector<int>> &adj, int src, int dist)
    {
        int n = adj.size();
        if (src >= n || dist >= n)
        {
            return {-1};
        }
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<bool> vis(n, 0);
        vector<int> res(n, INT_MAX);
        vis[src] = true;
        res[src] = 0;
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int d = p.second;
            for (int i = 0; i < adj[node].size(); i++)
            {
                int neigh = adj[node][i];
                if (!vis[neigh] && res[neigh] > d + 1)
                {
                    q.push({neigh, d + 1});
                    res[neigh] = d + 1;
                    vis[neigh] = true;
                }
            }
        }
        return res;
    }
    bool validPath(int n, vector<vector<int>> &edges, int s, int d)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0];
            int dist = edges[i][1];
            adj[src].push_back(dist);
            adj[dist].push_back(src);
        }
        vector<int> res = FindShotestPath(adj, s, d);
        int len = res.size();
        if (d >= len)
        {
            return false;
        }
        int resDist = res[d];
        if (resDist == INT_MAX)
        {
            return false;
        }
        return true;
    }
};