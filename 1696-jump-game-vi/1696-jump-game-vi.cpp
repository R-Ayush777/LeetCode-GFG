class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size()); // dp[i] stores max cost from ith index to last index
        dp[nums.size() - 1] = nums[nums.size() - 1];
        priority_queue<pair<int, int>> maxh; // max heap to store {dp[index], index}
        maxh.push({dp[nums.size() - 1], nums.size() - 1});
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            while (maxh.size() && maxh.top().second > i + k)
                maxh.pop();                     // we keep popping elements that are out of our window of size k to find the first top element inside our range.
            dp[i] = maxh.top().first + nums[i]; // That will be our max cost so we add it + current index cost
            maxh.push({dp[i], i});              // then we push the current dp[i] and i into max heap
        }
        return dp[0];
    }
};