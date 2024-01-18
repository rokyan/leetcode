// https://leetcode.com/problems/maximum-score-from-removing-stones/description/

class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        heap = [-a, -b, -c]
        heapify([a, b, c])
        res = 0

        while len(heap) > 1:
            x = -heappop(heap)
            y = -heappop(heap)
            res += 1
            x -= 1
            y -= 1

            if x > 0:
                heappush(heap, -x)
            if y > 0:
                heappush(heap, -y)

        return res
        