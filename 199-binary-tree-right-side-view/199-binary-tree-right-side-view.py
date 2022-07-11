# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        
        def Pre(node, depth):
            if not node:
                return
            if depth == len(ans):
                ans.append(node.val)
            Pre(node.right, depth+1)
            Pre(node.left, depth+1)
        
        Pre(root, 0)
        
        return ans
                
        
        
        