#User function Template for python3

class Solution:
    def farNumber(self,N,Arr):
        l = len(Arr)
        f = 0
        ans = [0]*l
        for i in range(l):
            for j in range(l-1, i , -1):
                if Arr[i]>Arr[j]:
                    ans[i]=j
                    f=1
                    break 
            if f==0:
                ans[i]=-1
            f=0
        return ans
                    

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tcs=int(input())
    for _ in range(tcs):
        N=int(input())
        Arr=[int(x) for x in input().split()]
        
        ob = Solution()
        ans = ob.farNumber(N,Arr)
        
        for i in ans:
            print(i,end=" ")
        print()
# } Driver Code Ends