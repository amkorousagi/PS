# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = []
    def traversal(self, current : TreeNode)->None:
        if current.left != None: self.traversal(current.left)
        self.res.append(current.val)
        if current.right != None : self.traversal(current.right)
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        self.res = []
        if root == None:
            return []
        self.traversal(root)
        return self.res