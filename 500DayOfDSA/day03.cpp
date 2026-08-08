class Solution {
public:
    void dfs(vector<vector<int>>&res,vector<vector<int>>&adj,vector<int>&temp,int node,int dist)
    {
        if(node==dist)
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<adj[node].size();i++)
        {
            int neigh=adj[node][i];
            temp.push_back(neigh);
            dfs(res,adj,temp,neigh,dist);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>temp;
        temp.push_back(0);
        int n=graph.size()-1;
        dfs(res,graph,temp,0,n);
        return res;
    }
};
int main()
{
    cout<<"Hello";
}