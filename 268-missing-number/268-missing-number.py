class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res = len(nums)
        i = 0
        for x in nums:
            res ^= x ^ i
            # res ^= i
            i += 1
        return res
