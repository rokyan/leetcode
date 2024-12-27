// https://leetcode.com/problems/count-the-number-of-k-free-subsets/description/

class Solution:
    def countTheNumOfKFreeSubsets(self, nums: List[int], k: int) -> int:
        nums.sort()

        tail = Counter()
        for num in nums:
            if num - k in tail:
                cnt = tail[num - k]
                del tail[num - k]
                tail[num] = cnt + 1
            else:
                tail[num] = 1

        n = max(tail.values()) + 2
        dp = [0] * (n)
        dp[0] = dp[1] = 1
        for i in range(2, n):
            dp[i] = dp[i - 1] + dp[i - 2]

        res = 1
        for v in tail.values():
            res *= dp[v + 1]

        return res        