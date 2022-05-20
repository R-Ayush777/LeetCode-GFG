class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        stk = []
        for i in range(len(s)):
            if s[i] in 'aAeEiIoOuU':
                stk.append(s[i])
        for i in range(len(s)):
            if s[i] in 'aAeEiIoOuU':
                s[i] = stk.pop()
        
        # str = "".join(s)
        print("".join(s))
        # print(s)
        return "".join(s)