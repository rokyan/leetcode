# https://leetcode.com/problems/max-consecutive-ones-ii/

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        flipped = 0
        res = 0
        l, r = 0, 0

        while r < len(nums):
            if nums[r] == 0:
                flipped += 1

            while flipped == 2:
                if nums[l] == 0:
                    flipped -= 1
                l += 1

            res = max(res, r - l + 1)
            r += 1

        return res
        