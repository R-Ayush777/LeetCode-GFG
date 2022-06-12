class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_map<int, int> idx;
        int currSum = 0, maxSum = 0;
        int l = 0, r = 0;

        for (r = 0; r < nums.size(); r++)
        {
            // cout << "idx[nums[r]]-> " << idx[nums[r]] << endl;
            if ((idx.find(nums[r]) != idx.end()) and idx[nums[r]] >= l)
            {
                currSum -= accumulate(nums.begin() + l, nums.begin() + idx[nums[r]] + 1, 0);
                l = idx[nums[r]] + 1;
            }
            currSum += nums[r];
            idx[nums[r]] = r;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};