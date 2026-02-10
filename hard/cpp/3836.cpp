// https://leetcode.com/problems/maximum-score-using-exactly-k-pairs/description/

class Solution
{
private:
    static constexpr long long inf = 1000'000'000'000'000LL;

public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        const int n = nums1.size();
        const int m = nums2.size();

        std::vector<std::vector<std::vector<long long>>> dp(n,
            std::vector<std::vector<long long>>(m, std::vector<long long>(k + 1, -inf)));

        long long res = -inf;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int take = 0; take <= k; take++)
                {
                    if (i > 0 && dp[i - 1][j][take] != -inf)
                    {
                        dp[i][j][take] = std::max(dp[i][j][take], dp[i - 1][j][take]);
                    }

                    if (j > 0 && dp[i][j - 1][take] != -inf)
                    {
                        dp[i][j][take] = std::max(dp[i][j][take], dp[i][j - 1][take]);
                    }

                    if (take == 1)
                    {
                        dp[i][j][take] = std::max(dp[i][j][take], 1LL * nums1[i] * nums2[j]);
                    }
                    else if (take > 1)
                    {
                        if (i > 0 && j > 0 && dp[i - 1][j - 1][take - 1] != -inf)
                        {
                            dp[i][j][take] = std::max(dp[i][j][take], 1LL * nums1[i] * nums2[j] + dp[i - 1][j - 1][take - 1]);
                        }
                    }

                    if (take == k)
                    {
                        res = std::max(res, dp[i][j][take]);
                    }
                }
            }
        }

        return res;
    }
};