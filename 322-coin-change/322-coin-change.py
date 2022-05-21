class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [9999999999] * (amount + 1)
        dp[0] = 0
        for j in range(amount):
            for i in range(len(coins)):
                if j + coins[i] <= amount:
                    dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1)

        return dp[amount] if dp[amount] < 99999999 else -1