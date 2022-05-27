class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        cnt = 0
        while min(num1, num2) > 0:
            if num1 < num2:
                num1, num2 = num2, num1
            ops, num1 = divmod(num1, num2)    
            cnt += ops
        return cnt
        