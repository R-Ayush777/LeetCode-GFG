class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        int row = 0, col = m;
        
        while (row <= n and col >= 0)
        {
            int curr = matrix[row][col];
            
            if (curr == target)
                return true;
            else if (curr < target)
                row++;
            else
                col--;
        }
        return false;
    }
};