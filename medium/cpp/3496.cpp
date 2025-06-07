// https://leetcode.com/problems/maximize-score-after-pair-deletions/description/

class Solution
{
public:
    int maxScore(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto t = nums[0];

        if (n % 2 == 0)
        {
            t += nums[1];
        }

        for (auto i = 0; i + (n % 2 == 0) < n; i++)
        {
            auto upd = nums[i];

            if (n % 2 == 0)
            {
                upd += nums[i + 1];
            }

            t = std::min(t, upd);
        }

        return std::accumulate(std::cbegin(nums), std::cend(nums), 0) - t;
    }
};