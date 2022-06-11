class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        sum -= x;
        if (sum == 0)
            return nums.size();

        int i = 0, j = 0, len = 0;
        int currSum = 0;
        
        for (j = 0; j < nums.size(); j++)
        {
            currSum += nums[j];
            while (i < nums.size() and currSum > sum)
                currSum -= nums[i++];
            if (currSum == sum)
                len = max(len, j - i + 1);
        }
        if (!len)
            return -1;
        return nums.size() - len;
    }
};