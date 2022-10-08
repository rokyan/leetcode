# https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort()
        
        cnt = 0
        ans = 0
        
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                cnt += 1
            ans += cnt
            
        return ans
        