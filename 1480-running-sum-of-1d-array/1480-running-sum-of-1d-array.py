class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        rs = [0]*(len(nums))
        rs[0] = nums[0]
        for i in range(1,len(nums)):
            rs[i] = rs[i-1]+nums[i]
        return rs
        