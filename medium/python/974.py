# https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        counts = [0] * k
        counts[0] = 1
        
        ans = 0
        sum = 0
        
        for num in nums:
            sum += num
            sum = (sum % k + k) % k
            
            ans += counts[sum]
            counts[sum] += 1
            
        return ans
        