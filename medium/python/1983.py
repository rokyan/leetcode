// https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/

class Solution:
    def widestPairOfIndices(self, nums1: List[int], nums2: List[int]) -> int:
        pref = { 0: -1 }
        res = 0
        sum = 0

        for i in range(0, len(nums1)):
            sum += nums1[i] - nums2[i]

            if sum in pref:
                res = max(res, i - pref[sum])
            else:
                pref[sum] = i

        return res
        