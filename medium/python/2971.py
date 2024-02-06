// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()

        res = -1
        s = sum(nums[:2])

        for e in nums[2:]:
            if e < s:
                res = e + s
            s += e

        return res