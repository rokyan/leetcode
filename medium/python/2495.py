# https://leetcode.com/problems/number-of-subarrays-having-even-product/description/

class Solution:
    def evenProduct(self, nums: List[int]) -> int:
        acc = 0
        odd = 0

        for num in nums:
            if num % 2 == 1:
                odd += 1
            else:
                odd = 0
            acc += odd

        n = len(nums)

        return n * (n + 1) // 2 - acc