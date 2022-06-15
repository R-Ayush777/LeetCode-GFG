class Solution
{
public:
    bool check(string &s1, string &s2)
    {
        if (s1.length() != s2.length() + 1)
            return false;
        int fp = 0, sp = 0;
        while (fp < s1.length())
        {
            if (s1[fp] == s2[sp])
                sp++, fp++;
            else
                fp++;
            if (fp == s1.length() and sp == s2.length())
                return true;
        }
        return false;
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b)
             { return a.length() < b.length(); });
             
        int n = words.size();
        vector<int> dp(words.size(), 1);
        int mx = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[i], words[j]) and 1 + dp[j] > dp[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > mx)
                mx = dp[i];
        }
        return mx;
    }
};