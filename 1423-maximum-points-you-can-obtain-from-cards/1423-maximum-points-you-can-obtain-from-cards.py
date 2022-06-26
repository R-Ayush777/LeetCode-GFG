class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        ans = total = sum(cardPoints[:k])
        n = len(cardPoints)
        for i in range(k-1, -1, -1):
            total += cardPoints[i+n-k]-cardPoints[i]
            ans = max(ans, total)
        return ans