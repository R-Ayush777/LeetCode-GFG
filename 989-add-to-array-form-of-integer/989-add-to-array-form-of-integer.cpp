class Solution {
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n = num.size();
        while (k)
        {
            if (!n)
                num.insert(num.begin(), k % 10);
            else
                 num[n] = (k += num[--n]) % 10;
            k /= 10;
        }
        return num;
    }
};