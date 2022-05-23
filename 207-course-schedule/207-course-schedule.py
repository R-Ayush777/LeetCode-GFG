from collections import deque


class Solution:
    # def findOrder(self, n, m, pre):
    def canFinish(self, n: int, pre: List[List[int]]) -> bool:
        indeg = [0 for i in range(n)]
        adj = [[] for i in range(n)]
        for i in pre:
            indeg[i[0]] += 1
            adj[i[1]].append(i[0])
            
        q = deque()
        for i in range(n):
            if indeg[i] == 0:
                q.append(i)
        st = []
        c = 0
        while len(q):
            node = q.popleft()
            st.append(node)
            c += 1
            for curr in adj[node]:
                indeg[curr] -= 1
                if indeg[curr] == 0:
                    q.append(curr)
        if c == n:
            return True
        return False