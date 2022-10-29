// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        const auto max_val = std::numeric_limits<int>::max();
        
        std::vector<int> dp(n, max_val);
        dp[0] = nums[0];
        
        for (std::size_t i = 1; i < std::size(nums); i++)
        {
            const auto pos = std::distance(std::begin(dp), std::lower_bound(std::begin(dp), std::end(dp), nums[i]));
            dp[pos] = nums[i];
        }
        
        return std::distance(std::begin(dp), std::find_if(std::rbegin(dp), std::rend(dp), [](auto e) { return e != max_val; }).base());
    }
};