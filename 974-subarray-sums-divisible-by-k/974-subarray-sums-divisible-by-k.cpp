class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        int currSum = 0;
        int ans = 0;
        int rem = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            rem = currSum % k;
            if (rem < 0)
                rem += k;
            if (mp[rem])
                ans += mp[rem];

            mp[rem]++;
        }
        return ans;
    }
};