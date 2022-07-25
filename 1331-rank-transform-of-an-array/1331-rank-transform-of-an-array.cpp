class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st(arr.begin(),arr.end());
        unordered_map<int,int> m;
        
        int rank=1;
        
        for(auto &x: st)
            m[x]=rank++;
        for(auto &x: arr)   
            x = m[x];
        
        return arr;
    }
};