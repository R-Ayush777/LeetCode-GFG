#User function Template for python3
import math

class Solution:
    def changeBits(self, N):
        K=int(math.log2(N))
        K=2**(K+1)-1
        return [K-N,K]

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        
        ob = Solution()
        ans = ob.changeBits(N)
        
        print(ans[0],ans[1])
# } Driver Code Ends