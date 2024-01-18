# https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float],
        start_node: int, end_node: int) -> float:

        graph = [[] for _ in range(0, n)]

        for (index, edge) in enumerate(edges):
            u, v, prob = *edge, succProb[index]
            graph[u].append((v, prob))
            graph[v].append((u, prob))

        heap = []
        heappush(heap, (-1.0, start_node))

        dst = [.0] * n
        dst[start_node] = 1.0

        while heap:
            _, u = heappop(heap)

            for v, prob in graph[u]:
                if dst[v] < dst[u] * prob:
                    dst[v] = dst[u] * prob
                    heappush(heap, (-dst[v], v))

        return dst[end_node]
        
