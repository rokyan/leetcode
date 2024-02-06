# https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        odd, even = 0, 1
        res = 0
        sum = 0

        for e in arr:
            sum += e

            if sum % 2 == 1:
                res += even
                odd += 1
            else:
                res += odd
                even += 1

            res %= 1000000007

        return res
        