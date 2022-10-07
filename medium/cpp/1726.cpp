// https://leetcode.com/problems/tuple-with-same-product/

class Solution 
{
public:
    int tupleSameProduct(std::vector<int>& nums) 
    {
        const auto n = std::size(nums);
        
        std::unordered_map<int, int> counts;
        
        for (std::size_t i = 0; i + 1 < n; i++)
        {
            for (std::size_t j = i + 1; j < n; j++)
            {
                counts[nums[i] * nums[j]]++;
            }
        }
        
        int ans = 0;
        
        for (const auto& e : counts)
        {
            ans += 4 * e.second * (e.second - 1);
        }
        
        return ans;
    }
};