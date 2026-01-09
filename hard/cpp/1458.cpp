// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

class Solution
{
private:
    static constexpr int inf = 1000'000'000;

public:
    int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        const int n = nums1.size();
        const int m = nums2.size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -inf));

        int res = -inf;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i > 0)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                }

                if (j > 0)
                {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
                }

                dp[i][j] = std::max(dp[i][j], nums1[i] * nums2[j]
                    + std::max(0, i > 0 && j > 0 ? std::max(0, dp[i - 1][j - 1]) : 0));

                res = std::max(res, dp[i][j]);
            }
        }

        return res;
    }
};