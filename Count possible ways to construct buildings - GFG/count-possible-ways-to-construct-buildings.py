#User function Template for python3

class Solution:
	def TotalWays(self, N):
	    MOD  = 1000000007
    	one,zero = 1, 1
    	for i in range(2,N+1):
    	    preOne = one
    	    one  = (one+zero)%MOD
    	    zero = preOne%MOD
    	oneSide = (one+zero)%MOD
        return (oneSide*oneSide)%MOD

#{ 
#  Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		N = int(input())
		ob = Solution()
		ans = ob.TotalWays(N)
		print(ans)
# } Driver Code Ends