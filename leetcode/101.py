# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetricSame(self, p:TreeNode, q:TreeNode)->bool:
        if p == None and q == None:
            return True
        if p != None and q == None:
            return False
        if p == None and q != None:
            return False
        return (p.val == q.val) and (self.isSymmetricSame(p.left, q.right)) and (self.isSymmetricSame(p.right, q.left))
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        return self.isSymmetricSame(root.left, root.right)
        