



from typing import List


class Solution:
    def longestPath(self, mat: List[List[int]], n: int, m: int, xs: int, ys: int, xd: int, yd: int) -> int:

        if mat[xs][ys] == 0 or mat[xd][yd] == 0:
            # start or end pos is blocked, return -1
            return -1

        self.ans = 0
        self.dist = 0

        def dfs(i, j):
            # out of bounds
            if i < 0 or i >= n or j < 0 or j >= m:
                return
            # blocked or already visited
            if mat[i][j] == 0 or mat[i][j] == -1:
                return
            # destination reached, update ans with max dist travelled thus far
            if i == xd and j == yd:
                self.ans = max(self.dist, self.ans)

            # visit the current cell in the given grid itself
            # by negative val, saving on extra space
            # increase distance as well
            mat[i][j] = -1
            self.dist += 1

            # 4-directional dfs calls
            dfs(i+1, j)
            dfs(i-1, j)
            dfs(i, j+1)
            dfs(i, j-1)

            # backtrack
            mat[i][j] = 1
            self.dist -= 1

        dfs(xs, ys)
        return self.ans


#{ 
#  Driver Code Starts


class IntArray:

    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()



class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=IntArray().Input(2)
        
        
        b=IntArray().Input(4)
        
        
        mat=IntMatrix().Input(a[0], a[0])
        
        obj = Solution()
        res = obj.longestPath(mat,a[0],a[1],b[0],b[1],b[2],b[3])
        
        print(res)
        


# } Driver Code Ends