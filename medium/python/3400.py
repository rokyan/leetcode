// https://leetcode.com/problems/maximum-number-of-matching-indices-after-right-shifts/description/

class Solution:
    def maximumMatchingIndices(self, nums1: List[int], nums2: List[int]) -> int:
        res = 0
        for i in range(0, len(nums1)):
            res = max(res, sum(1 for i in range(0, len(nums1)) if nums1[i] == nums2[i]))
            nums1 = nums1[-1:] + nums1[:-1]
        return res