# https://leetcode.com/problems/plates-between-candles/

class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        pos = [i for i in range(0, len(s)) if s[i] == '|']
        res = [0] * len(queries)

        for i, (left, right) in enumerate(queries):
            qleft = bisect.bisect_left(pos, left)
            qright = bisect.bisect_right(pos, right) - 1

            if qright > qleft:
                res[i] = pos[qright] - pos[qleft] - (qright - qleft)

        return res