# https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/

class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        m = len(matrix[0])
        
        par_xor = [[0] * m for _ in range(n)]
        heap = []
        
        for i in range(n):
            for j in range(m):
                par_xor[i][j] = matrix[i][j]
                
                if i > 0:
                    par_xor[i][j] ^= par_xor[i - 1][j]
                    
                if j > 0:
                    par_xor[i][j] ^= par_xor[i][j - 1]
                    
                if i > 0 and j > 0:
                    par_xor[i][j] ^= par_xor[i - 1][j - 1]
                    
                heappush(heap, par_xor[i][j])
                
                if len(heap) > k:
                    heappop(heap)
        
        return heap[0]
        