# https://leetcode.com/problems/find-leaves-of-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []

        def dfs(root):
            if not root:
                return -1

            d = 1 + max(dfs(root.left), dfs(root.right))

            if len(res) == d:
                res.append([])

            res[d].append(root.val)

            return d

        dfs(root)

        return res
        