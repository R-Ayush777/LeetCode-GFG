class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        
        unordered_set<string> per;
        for (int i=0;i<=s.size()-k;i++)
            per.insert(s.substr(i,k));
        
        return per.size()==pow(2,k);
    }
};