class Solution:
    def removePalindromeSub(self, S: str) -> int:
        if not S: return 0
        return 1 if S == S[::-1] else 2