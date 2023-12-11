// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        val = max(nums)
        left, right = 0, 0
        cnt = 0
        res = 0

        while left < len(nums):
            while cnt < k and right < len(nums):
                if nums[right] == val:
                    cnt += 1
                right += 1

            if cnt < k:
                break

            res += len(nums) - right + 1

            if nums[left] == val:
                cnt -= 1

            left += 1

        return res
        