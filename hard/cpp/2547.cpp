// https://leetcode.com/problems/minimum-cost-to-split-an-array/description/

class Solution
{
public:
    int minCost(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> dp(n, -1);
        dp[0] = k;

        for (auto i = 1; i < n; i++)
        {
            std::unordered_map<int, int> cnt;

            for (int j = i, len = 0; j >= 0; j--)
            {
                if (const auto it = cnt.find(nums[j]); it != std::end(cnt))
                {
                    if (it->second == 1)
                    {
                        len += 2;
                    }
                    else
                    {
                        len++;
                    }

                    it->second++;
                }
                else
                {
                    cnt.emplace(nums[j], 1);
                }

                const auto updated = k + len + (j > 0 ? dp[j - 1] : 0);

                if (dp[i] == -1 || dp[i] > updated)
                {
                    dp[i] = updated;
                }
            }
        }

        return dp.back();
    }
};