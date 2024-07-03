# https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        return self.solve(root)

    def solve(self, root, parent = None, gparent = None):
        if root is None:
            return 0
            
        return (0 if gparent is None or gparent.val % 2 == 1 else root.val) + \
            self.solve(root.left, root, parent) + \
            self.solve(root.right, root, parent)