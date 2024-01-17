// https://leetcode.com/problems/minimum-cost-to-connect-sticks/description/

class Solution:
    def connectSticks(self, sticks: List[int]) -> int:
        heapify(sticks)
        n = len(sticks)
        res = 0

        while n > 1:
            n -= 1
            first, second = heappop(sticks), heappop(sticks)
            heappush(sticks, first + second)
            res += first + second

        return res
        