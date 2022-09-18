// https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution
{
public:
    int subarraysDivByK(std::vector<int>& nums, int k)
    {
        std::vector<int> counts(k);
        counts[0] = 1;
        
        int sum = 0;
        int ans = 0;
        
        for (auto e : nums)
        {
            sum += e;
            sum = (sum % k + k) % k;
            
            ans += counts[sum];
            
            counts[sum]++;
        }
        
        return ans;
    }
};