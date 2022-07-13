#User function Template for python3

class Solution:
   def assignmentProblem(self, Arr, N):
       n=N
       l=Arr
       m = []
       mybeg = []
       for i in range(n):
           m.append(l[i*n:(i+1)*n])
           mybeg.append(l[i*n:(i+1)*n])
       def util():
           u, v, ind = [0]*n, [0]*n, [-1]*n
           for i in range(n):
               links, mins, visited = [-1]*n, [1000]*n, [False]*n
               marki, markj = i, -1
               while marki != -1:
                   j = -1
                   for j1 in range(n):
                       if not visited[j1]:
                           current = m[marki][j1] - u[marki] - v[j1]
                           if current < mins[j1]:
                               mins[j1] = current
                               links[j1] = markj
                           if j == -1 or mins[j1] < mins[j]:
                               j = j1
                   delta = mins[j]
                   for j1 in range(n):
                       if visited[j1]:
                           u[ind[j1]] += delta;  v[j1] -= delta
                       else:
                           mins[j1] -= delta
                   u[i] += delta
                   visited[j] = True
                   markj, marki = j, ind[j]
               while links[j] != -1:
                   ind[j] = ind[links[j]]
                   j = links[j]
               ind[j] = i
           return [(ind[j], j) for j in range(n)]
       return (sum(mybeg[x][y] for x,y in util()))

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        Arr=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.assignmentProblem(Arr,N))
# } Driver Code Ends