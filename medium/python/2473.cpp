# https://leetcode.com/problems/minimum-cost-to-buy-apples/

class Solution:
    def minCost(self, n: int, roads: List[List[int]], appleCost: List[int], k: int) -> List[int]:
        graph = [[] for _ in range(0, n)]

        for u, v, cost in roads:
            graph[u - 1].append((v - 1, cost))
            graph[v - 1].append((u - 1, cost))

        def findShortest(start):
            dst = [float('inf') for v in range(0, n)]
            dst[start] = 0

            heap = []
            heappush(heap, (0, start))

            while heap:
                _, v = heappop(heap)

                for to, c in graph[v]:
                    if dst[to] > dst[v] + c:
                        dst[to] = dst[v] + c
                        heappush(heap, (dst[to], to))

            return min(dst[v] + k * dst[v] + appleCost[v] for v in range(0, n))

        return [findShortest(v) for v in range(0, n)]