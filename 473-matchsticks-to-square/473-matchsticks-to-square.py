class Solution:
    def makesquare(self, matchsticks: List[int]) -> bool:
        length = sum(matchsticks)//4
        sides = [0]*4
        if sum(matchsticks)/4 != length:
            return False

        matchsticks.sort(reverse=True)

        def BckT(i):
            if i == len(matchsticks):
                return True
            for j in range(4):
                if sides[j]+matchsticks[i] <= length:
                    sides[j] += matchsticks[i]
                    if BckT(i+1):
                        return True
                    sides[j] -= matchsticks[i]
            return False
            
        return BckT(0)