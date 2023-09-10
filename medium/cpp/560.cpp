// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution
{
public:
    int subarraySum(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> prefs;
        prefs[0] = 1;
        
        auto sum = 0;
        auto ans = 0;
        
        for (auto num : nums)
        {
            sum += num;
            
            const auto it = prefs.find(sum - k);
            
            if (it != std::end(prefs))
            {
                ans += it->second;
            }
            
            ++prefs[sum];
        }
        
        return ans;
    }
};