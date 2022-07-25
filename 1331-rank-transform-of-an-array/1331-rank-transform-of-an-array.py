class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:       
        mp = {k: v+1 for v, k in enumerate(sorted(set(arr)))}
        return [mp[i] for i in arr]
        