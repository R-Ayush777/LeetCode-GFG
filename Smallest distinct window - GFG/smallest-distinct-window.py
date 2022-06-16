#User function Template for python3

class Solution:
    def findSubString(self, str):
        st = set(str)
        lenSet = len(st)
        mp = {}
        i, j = 0, 0
        ans = 1000000
        while j < len(str):
            mp[str[j]] = mp.get(str[j], 0)+1
            if len(mp) == lenSet:
                while mp[str[i]] > 1:
                    mp[str[i]] -= 1
                    i += 1
                ans = min(ans, j-i+1)
            j += 1
        return ans
    
    

#{ 
#  Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while(T > 0):
    	str = input()
    	ob=Solution()
    	print(ob.findSubString(str))
    	
    	T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends