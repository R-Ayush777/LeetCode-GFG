class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> triangle;
        for(int i=0;i<rows;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=triangle[i-1][j]+triangle[i-1][j-1];
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};