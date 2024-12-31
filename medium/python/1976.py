// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(list)

        for road in roads:
            graph[road[0]].append((road[1], road[2]))
            graph[road[1]].append((road[0], road[2]))

        heap = [(0, 0)]
        dst = [10 ** 18] * n
        dst[0] = 0

        while len(heap) > 0:
            d, v = heappop(heap)

            if -d > dst[v]:
                continue

            for to, w in graph[v]:
                if dst[to] > dst[v] + w:
                    dst[to] = dst[v] + w
                    heappush(heap, (-dst[to], to))

        dp = [-1] * n
        dp[0] = 1

        def rec(v):
            if dp[v] != -1:
                return dp[v]

            dp[v] = 0

            for to, w in graph[v]:
                if dst[to] + w == dst[v]:
                    dp[v] += rec(to)
                    dp[v] %= 10**9 + 7

            return dp[v]

        return rec(n - 1)    