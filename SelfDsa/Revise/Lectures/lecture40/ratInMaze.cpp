#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>>&matrix)
{
    if((x>=0&&x<=n)&&(y>=0&&y<=n)&&(visited[x][y]==0)&&(matrix[x][y]==1))
    {
        return true;
    }
    return false;

}
void solve(int x, int y, vector<vector<int>> matrix, vector<string> &ans, vector<vector<int>> &visited,int n,string path)
{
    if(x==n&&y==n)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    // down
    int newx=x+1;
    int newy=y;
    if(isSafe(newx,newy,n,visited,matrix))
    {
        path.push_back('D');
        solve(newx,newy,matrix,ans,visited,n,path);
        path.pop_back();
    }
    // left
     newx = x;
     newy = y-1;
    if (isSafe(newx, newy, n, visited, matrix))
    {
        path.push_back('L');
        solve(newx, newy, matrix, ans, visited, n, path);
        path.pop_back();
    }
    newx = x;
    newy = y+1;
    if (isSafe(newx, newy, n, visited, matrix))
    {
        path.push_back('R');
        solve(newx, newy, matrix, ans, visited, n, path);
        path.pop_back();
    }
    newx = x-1;
    newy = y ;
    if (isSafe(newx, newy, n, visited, matrix))
    {
        path.push_back('R');
        solve(newx, newy, matrix, ans, visited, n, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>>matrix)
{
    int n=matrix.size()-1;
    vector<string>ans;
    vector<vector<int>>visited=matrix;
    string path="";
    int srcx=0;
    int srcy=0;
    if(matrix[0][0]==0)
    {
        return ans;
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            visited[i][j]=0;
        }
    }
    solve(srcx,srcy,matrix,ans,visited,n,path);
    return ans;

}
int main()
{
    vector<vector<int>> matrix =
        {
            {1, 0, 0, 0},
            {1, 1, 0, 1},
            {0, 1, 0, 0},
            {1, 1, 1, 1}};

    vector<string> paths = findPath(matrix);

    if (paths.size() == 0)
    {
        cout << "No path found.\n";
    }
    else
    {
        cout << "Paths:\n";
        for (string p : paths)
        {
            cout << p << endl;
        }
    }

    return 0;
    return 0;
}
