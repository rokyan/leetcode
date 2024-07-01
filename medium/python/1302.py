# https://leetcode.com/problems/deepest-leaves-sum/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        q = deque([root])

        while q:
            cur_q = q
            q = deque()

            for node in cur_q:
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return sum(node.val for node in cur_q)
        