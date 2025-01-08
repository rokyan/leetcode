# https://leetcode.com/problems/count-nodes-equal-to-sum-of-descendants/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        def solve(root):
            if root is None:
                return 0, 0
            left = solve(root.left)
            right = solve(root.right)
            tot = left[1] + right[1]

            if root.val == left[0] + right[0]:
                tot += 1

            return root.val + left[0] + right[0], tot

        return solve(root)[1]        