# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        if preorder and inorder:
            r = inorder.index(preorder.pop(0))
            root = TreeNode(inorder[r])
            root.left = self.buildTree(preorder, inorder[0:r])
            root.right = self.buildTree(preorder, inorder[r+1:])
            return root
        