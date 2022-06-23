#User function Template for python3
class Solution:

	def countStrings(self,n):
	    MOD  = 1000000007
    	one,zero = 1, 1
    	for i in range(2,n+1):
    	    preOne = one
    	    one  = (one+zero)%MOD
    	    zero = preOne%MOD
        return (one+zero)%MOD
    	    

#{ 
#  Driver Code Starts
#Initial Template for Python 3



# Driver code 
if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n=int(input())
        ob = Solution()
        ans = ob.countStrings( n)
        print(ans)
        tc=tc-1
# } Driver Code Ends