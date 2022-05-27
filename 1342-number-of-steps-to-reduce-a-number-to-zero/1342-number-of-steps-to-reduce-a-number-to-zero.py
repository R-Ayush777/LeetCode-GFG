class Solution:
    def numberOfSteps(self, num: int) -> int:
        req = num
        cnt = 0
        while req:
            if req%2:
                req-=1
            else:
                req/=2
            cnt+=1
        return int(cnt+req)
        