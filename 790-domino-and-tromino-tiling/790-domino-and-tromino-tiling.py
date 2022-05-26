class Solution(object):
    def numTilings(self, n):
        dp, dpa = [1, 2] + [0] * n, [1] * n
        for i in range(2, n):
            dp[i] = (dp[i - 1] + dp[i - 2] + dpa[i - 1] * 2) % 1000000007
            dpa[i] = (dp[i - 2] + dpa[i - 1]) % 1000000007
        return dp[n - 1]