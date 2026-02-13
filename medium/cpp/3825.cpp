// https://leetcode.com/problems/longest-strictly-increasing-subsequence-with-non-zero-bitwise-and/description/

class Solution
{
private:
    static constexpr int inf = 1000'000'007;

public:
    int longestSubsequence(const std::vector<int>& nums)
    {
        const int n = nums.size();

        int res = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            std::vector<int> dp(n + 1, inf);
            dp[0] = -inf;

            int maxLen = 0;

            for (int i = 0; i < n; i++)
            {
                if (nums[i] & (1 << bit))
                {
                    const int pos = std::distance(
                        dp.begin(),
                        std::lower_bound(dp.begin(), dp.end(), nums[i])
                    );

                    dp[pos] = nums[i];
                    maxLen = std::max(maxLen, pos);
                }
            }

            res = std::max(res, maxLen);
        }

        return res;
    }
};