# https://leetcode.com/problems/painting-the-walls/description/

class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        n = len(cost)
        dp = [1e9] * (n + 1)
        dp[0] = 0

        for i in range(1, n + 1):
            ndp = dp[:]
            for j in range(1, n + 1):
                if time[i - 1] + 1 >= j:
                    ndp[j] = min(ndp[j], cost[i - 1])
                else:
                    ndp[j] = min(ndp[j], dp[j - time[i - 1] - 1] + cost[i - 1])
            dp = ndp

        return dp[-1]
        