# https://leetcode.com/problems/balance-a-binary-search-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        values = []
        self.traverse(root, values)
        return self.build(values, 0, len(values))

    def traverse(self, root, values):
        if root is not None:
            self.traverse(root.left, values)
            values.append(root.val)
            self.traverse(root.right, values)

    def build(self, values, left, right):
        if left < right:
            mid = left + (right - left) // 2
            return TreeNode(values[mid], self.build(values, left, mid), self.build(values, mid + 1, right))