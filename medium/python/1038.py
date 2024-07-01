# https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        sum = [0]
        self.solve(root, sum)
        return root

    def solve(self, root, sum):
        if root is None:
            return

        self.solve(root.right, sum)
        sum[0] += root.val
        root.val = sum[0]
        self.solve(root.left, sum)
        