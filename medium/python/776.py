# https://leetcode.com/problems/split-bst/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def splitBST(self, root: Optional[TreeNode], target: int) -> List[Optional[TreeNode]]:
        return self.split(root, target)

    def split(self, root, target):
        if not root:
            return [None, None]

        if root.val > target:
            left, right = self.split(root.left, target)
            root.left = right
            return [left, root]
        else:
            left, right = self.split(root.right, target)
            root.right = left
            return [root, right]