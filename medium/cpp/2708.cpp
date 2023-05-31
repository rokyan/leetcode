// https://leetcode.com/problems/maximum-strength-of-a-group/description/

class Solution
{
public:
    long long maxStrength(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto res = std::accumulate(std::begin(nums), std::end(nums), 1LL, std::multiplies<>{});

        for (auto mask = 1; mask < (1 << n); mask++)
        {
            auto cur = 1LL;

            for (auto i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    cur *= nums[i];
                }
            }

            res = std::max(res, cur);
        }

        return res;
    }
};