# https://leetcode.com/problems/first-missing-positive/description/

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        for i in range(0, n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = n + 1

        for num in nums:
            val = abs(num)

            if val != n + 1 and nums[val - 1] > 0:
                nums[val - 1] *= -1

        for i, num in enumerate(nums):
            if num > 0:
                return i + 1

        return n + 1 