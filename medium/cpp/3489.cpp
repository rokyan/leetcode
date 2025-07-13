// https://leetcode.com/problems/zero-array-transformation-iv/description/

class Solution
{
public:
    int minZeroArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(queries));
        auto solved = false;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto canMakeZero = true;

            for (auto i = 0; i < std::size(nums) && canMakeZero; i++)
            {
                canMakeZero = check(nums[i], i, queries, mid);
            }

            if (canMakeZero)
            {
                hi = mid - 1;
                solved = true;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return solved ? lo : -1;
    }

private:
    bool check(int num, int pos, const std::vector<std::vector<int>>& queries, int take)
    {
        std::vector<int> values;

        for (auto i = 0; i < take; i++)
        {
            if (queries[i][0] <= pos && pos <= queries[i][1])
            {
                values.push_back(queries[i][2]);
            }
        }

        const auto m = std::size(values);

        if (m == 0)
        {
            return num == 0;
        }

        std::vector<std::vector<char>> dp(m, std::vector<char>(num + 1));

        for (auto i = 0; i < m; i++)
        {
            dp[i][0] = true;

            for (auto j = 1; j <= num; j++)
            {
                if (j - values[i] == 0)
                {
                    dp[i][j] = true;
                    continue;
                }

                if (i > 0)
                {
                    dp[i][j] |= dp[i - 1][j];

                    if (j - values[i] > 0)
                    {
                        dp[i][j] |= dp[i - 1][j - values[i]];
                    }
                }
            }
        }

        return dp[m - 1][num];
    }
};