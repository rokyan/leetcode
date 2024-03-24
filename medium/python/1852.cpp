# https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/

class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        cnt = 0
        res = [0] * (len(nums) - k + 1)

        for i in range(0, len(nums)):
            if freq[nums[i]] == 0:
                cnt += 1
            freq[nums[i]] += 1

            if i >= k - 1:
                res[i - k + 1] = cnt
                if freq[nums[i - k + 1]] == 1:
                    cnt -= 1
                freq[nums[i - k + 1]] -= 1

        return res