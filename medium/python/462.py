# https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()

        l, r = 0, len(nums) - 1
        res = 0

        while l < r:
            res += nums[r] - nums[l]
            l += 1
            r -= 1

        return res
        