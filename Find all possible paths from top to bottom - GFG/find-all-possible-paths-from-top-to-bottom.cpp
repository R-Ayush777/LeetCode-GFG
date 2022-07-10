// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;

    void DFS(int i, int j, int x,int y, vector<vector<int>> &grid, vector<int> temp)
    {
        if(i>=grid.size() or j>=grid[0].size())
            return;
        int t = grid[i][j];
        temp.push_back(t);
        if(grid[i][j]==grid[grid.size()-1][grid[0].size()-1])
            ans.push_back(temp);
        DFS(i+1, j, x, y, grid, temp);
        DFS(i, j+1, x, y, grid, temp);
        
        return;
    }

    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        int x=grid[0][0];
        int y=grid[n-1][m-1];
        
        vector<int> temp;
        DFS(0, 0, x, y, grid, temp);
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends