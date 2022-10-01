# https://leetcode.com/problems/brick-wall/

class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:       
        counts = collections.defaultdict(int)
        
        for row in wall:
            pos = 0
            
            for i in row[:-1]:
                pos += i
                counts[pos] += 1
                
        values = counts.values()
                
        return len(wall) - (0 if len(values) == 0 else max(counts.values()))