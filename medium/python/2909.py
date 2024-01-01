# https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        rem = nums[:]

        for i in range(len(rem) - 2, 0, -1):
            rem[i] = min(rem[i], rem[i + 1])

        min_so_far = nums[0]
        res = -1

        for i in range(1, len(nums) - 1):
            if min_so_far < nums[i] and nums[i] > rem[i + 1]:
                upd = min_so_far + nums[i] + rem[i + 1]
                res = upd if res == -1 else min(res, upd)
            min_so_far = min(min_so_far, nums[i])

        return res

        