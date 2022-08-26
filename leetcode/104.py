# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depth(self,current : TreeNode) -> int:
        if current == None:
            return 0
        return max([self.depth(current.left)+1,self.depth(current.right)+1])
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0;
        return self.depth(root)
        