class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        up = [0]*n
        down = [0]*n
        up[0]=down[0]=1
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                up[i]=down[i-1]+1
                down[i]=down[i-1]
            elif nums[i]<nums[i-1]:
                down[i]=up[i-1]+1
                up[i]=up[i-1]
            else:
                down[i],up[i]=down[i-1],up[i-1]
                
        return max(up[n-1],down[n-1])

            
            
        