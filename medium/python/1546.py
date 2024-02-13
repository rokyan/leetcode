# 1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target

class Solution:
    def maxNonOverlapping(self, nums: List[int], target: int) -> int:
        dp = [0] * len(nums)
        pref = { 0: -1 }
        s = 0

        for i in range(0, len(nums)):
            s += nums[i]

            if i > 0:
                dp[i] += dp[i - 1]

            if s - target in pref:
                dp[i] = max(dp[i], 1 + (0 if pref[s - target] == -1 else dp[pref[s - target]]))

            pref[s] = i

        return dp[-1]       