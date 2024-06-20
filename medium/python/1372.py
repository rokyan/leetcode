# https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(root):
            if root is None:
                return [0, 0]

            lens = [0, 0]

            if root.left is not None:
                sub_lens = dfs(root.left)
                lens[0] = 1 + sub_lens[-1]
            if root.right is not None:
                sub_lens = dfs(root.right)
                lens[-1] = 1 + sub_lens[0]

            nonlocal res
            res = max(res, lens[0], lens[-1])

            return lens

        dfs(root)

        return res
        