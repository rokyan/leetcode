# https://leetcode.com/problems/count-the-number-of-houses-at-a-certain-distance-i/

class Solution:
    def countOfPairs(self, n: int, x: int, y: int) -> List[int]:
        res = [0] * n

        for s in range(1, n):
            for f in range(s + 1, n + 1):
                res[min(f - s, abs(s - x) + abs(f - y) + 1, abs(s - y) + abs(f - x) + 1) - 1] += 1

        return [e * 2 for e in res]