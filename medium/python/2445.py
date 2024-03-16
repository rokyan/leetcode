// https://leetcode.com/problems/number-of-nodes-with-value-one/description/

class Solution:
    def numberOfNodes(self, n: int, queries: List[int]) -> int:
        marks = [False] * (n + 1)

        for query in queries:
            marks[query] ^= True

        def count(v, acc = False):
            if v > n:
                return 0
            acc ^= marks[v]
            return acc + count(v * 2, acc) + count(v * 2 + 1, acc)

        return count(1)