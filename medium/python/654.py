# https://leetcode.com/problems/maximum-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        return self.build(nums, 0, len(nums))

    def build(self, nums, left, right):
        if left == right:
            return None

        idx = left
        for i in range(left, right):
            if nums[i] > nums[idx]:
                idx = i

        return TreeNode(nums[idx], self.build(nums, left, idx), self.build(nums, idx + 1, right))