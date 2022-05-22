class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length(), res = 0;
        int dp[n + 1][n + 1]; // dp[i][j] -> signifies if s[i] to s[j] is palindrome or not. At the end we count all values that are 1 to calculate all possibilities.
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                    dp[i][j] = 1; // for case where length of string is 1
                else if (j - i == 1)
                    dp[i][j] = (s[i] == s[j]) ? 1 : 0; // for case where length of string is 2
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1] == 1) ? 1 : 0; // for case where length of string > 2
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res += dp[i][j];
        return res;
    }
};