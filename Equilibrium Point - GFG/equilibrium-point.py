# User function Template for python3

class Solution:
    # Complete this function
    
    #Function to find equilibrium point in the array.
    def equilibriumPoint(self,A, N):
        if N==1:
            return 1
        pre = []
        tsum = 0
        
        for x in A:
            tsum += x
            pre.append(tsum)
        
        for i in range(1,N-1):
            ls = pre[i] - A[i]
            rs = tsum - pre[i]
            if ls == rs:
                return i+1
                
        return -1
            


#{ 
#  Driver Code Starts
# Initial Template for Python 3

import math


def main():

    T = int(input())

    while(T > 0):

        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob=Solution()

        print(ob.equilibriumPoint(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends