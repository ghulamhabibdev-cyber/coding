class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node,int& count) {
        if (adj[node].size() == 0) {
            return;
        }
        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];
            if (!vis[neigh]) {
                count++;
                vis[neigh]=true;
                dfs(adj, vis, neigh, count);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int count = 0;
        vector<bool> vis(n, 0);
        vis[0]=true;
        dfs(rooms, vis, 0, count);
        if (count == n - 1) {
            return true;
        }
        return false;
    }
};