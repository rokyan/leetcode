// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const auto n = std::size(nums1);
        const auto m = std::size(nums2);

        std::vector<std::vector<int>> dp(n, std::vector<int>(m));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    dp[i][j] = 1 + (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0);
                }

                res = std::max(res, dp[i][j]);
            }
        }

        return res;
    }
};