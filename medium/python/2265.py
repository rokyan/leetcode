# https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        cnt = [0]
        self.solve(root, cnt)
        return cnt[0]

    def solve(self, root, cnt):
        if root is None:
            return (0, 0)

        cur = tuple(sum(x) for x in zip((1, root.val), self.solve(root.left, cnt), self.solve(root.right, cnt)))

        if root.val == cur[1] // cur[0]:
            cnt[0] += 1

        return cur