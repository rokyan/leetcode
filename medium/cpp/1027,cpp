// https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution
{
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        const auto n = std::size(nums);
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(1000 + 1, 1));
        
        int ans = 0;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                const int d = nums[i] - nums[j] + 500;
                
                dp[i][d] = std::max(dp[i][d], dp[j][d] + 1);
                
                ans = std::max(ans, dp[i][d]);
            }
        }
        
        return ans;
    }
};