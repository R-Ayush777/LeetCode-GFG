
class Solution:
    def minSum(self, arr, n):
        if n<=2:
            return sum(arr)
        arr.sort()
        n1, n2 = 0, 0
        
        for i in range(0, n, 2):
            n1=(10*n1+arr[i])
            try:
                n2=(10*n2+arr[i+1])
            except:
                pass
        
        return n1+n2
        
    

#{ 
#  Driver Code Starts

import heapq as hq

if __name__ == '__main__':
    T = int(input())

    for tcs in range(T):
        n = int(input())
        arr = [int(x) for x in input().split()]
        ob=Solution()
        print(ob.minSum(arr,n))

# } Driver Code Ends