class Solution:
    def candy(self, ratings: List[int]) -> int:
        res = len(ratings) * [1]
        for i in range(1, len(ratings)):  # from left to right
            if ratings[i] > ratings[i-1]:
                res[i] = res[i-1] + 1
        for i in range(len(ratings)-1, 0, -1):  # from right to left
            if ratings[i-1] > ratings[i]:
                res[i-1] = max(res[i-1], res[i]+1)
        return sum(res)
        