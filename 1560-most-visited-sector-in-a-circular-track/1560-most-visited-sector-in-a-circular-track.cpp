class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> ans;
        int m = rounds.size();

        if (rounds[0] <= rounds[m - 1])
        {
            for (int i = rounds[0]; i <= rounds[m - 1]; i++)
                ans.push_back(i);
            return ans;
        }
        else
        {
            for (int i = 1; i <= rounds[m - 1]; i++)
                ans.push_back(i);
            for (int i = rounds[0]; i <= n; i++)
                ans.push_back(i);
        }
        return ans;
    }
};