class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> fq;
        fq[0] = 1;

        for (auto x : nums)
        {
            sum += x;
            int rsum = sum - k;
            if (fq.find(rsum) != fq.end())
                ans += fq[rsum];
            fq[sum]++;
        }
        return ans;
    }
};