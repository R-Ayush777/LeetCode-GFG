class Solution {
    
    //possible moving directions {up, left, right, down}
    vector<vector<int>> dirs = {
            {-1,0},
    {0,-1},        {0,1},
            {1,0}
    };
    
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp, int prev) 
    {
        //boundary conditon
        if(r<0 || r>=matrix.size() || c<0 || c>=matrix[0].size()) return 0;
        
        //if current value is less than or equal to the previous value return 0;
        if(matrix[r][c] <= prev) return 0;
        
        //if we have already the path length of the cell, we return it (dp concept)
        if(dp[r][c] != -1) return dp[r][c];
        int best = 0; //store best path length
        
        //moving in all 4 directions and call dfs function
        for(auto dir : dirs) {
            int next_r = dir[0] + r;
            int next_c = dir[1] + c;
            int cur = dfs(matrix, next_r, next_c, dp, matrix[r][c]);
            best = max(best, cur); //store max. path length
        }
        
        return dp[r][c] = best + 1; //return path length of the cell
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        //getting no. of row and col of the matrix
        int row = matrix.size(), col = matrix[0].size();
        
        //for dp, create mxn matrix and initialize it with -1
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        //store longest path
        int longest_path = 0;
        
        //traverse through the matrix
        for(int i=0; i<row; i++) 
        {
            for(int j=0; j<col; j++) 
            {
                int path = dfs(matrix, i, j, dp, -1000000); //call dfs function
                longest_path = max(longest_path, path); //store the maximum path
            }
        }
        
        return longest_path; //return maximum path
    }
};