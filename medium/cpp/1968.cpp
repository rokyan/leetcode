// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        std::sort(std::begin(nums), std::end(nums));
        
        std::size_t pos = 0;
        std::vector<int> ans(n);
        
        for (std::size_t i = 0; i < n; i += 2)
        {
            ans[i] = nums[pos++];
        }
        
        for (std::size_t i = 1; i < n; i += 2)
        {
            ans[i] = nums[pos++];
        }
        
        return ans;
    }
};