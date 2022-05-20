class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // dp[0][0] = 1;
        if (grid[0][0] == 0)
            dp[0][0] = 1;
        for (int i = 1; i < n; i++)
            dp[i][0] = (grid[i][0] == 0 and dp[i - 1][0]) ? 1 : 0;
        for (int i = 1; i < m; i++)
            dp[0][i] = (grid[0][i] == 0 and dp[0][i - 1]) ? 1 : 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
                if (!grid[i][j])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }

        return dp[n - 1][m - 1];
    }
};
