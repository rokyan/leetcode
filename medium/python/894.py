# https://leetcode.com/problems/all-possible-full-binary-trees/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        return self.gen(n)

    def gen(self, n):
        if n % 2 == 0:
            return []

        if n == 1:
            return [TreeNode()]

        res = []

        for i in range(1, n, 2):
            left = self.gen(i)
            right = self.gen(n - i - 1)

            for l in left:
                for r in right:
                    res.append(TreeNode(0, l, r))

        return res
        