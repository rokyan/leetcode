# https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        
        n = len(nums)
        
        ans = [0] * n
        pos = 0
        
        for i in range(0, n, 2):
            ans[i] = nums[pos]
            pos += 1
            
        for i in range(1, n, 2):
            ans[i] = nums[pos]
            pos += 1
            
        return ans
        