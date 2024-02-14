// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/

class Solution
{
public:
    int minMoves(std::vector<int>& nums, int limit)
    {
        std::vector<int> cnt(2 * limit + 2);

        const auto n = static_cast<int>(std::size(nums));

        for (auto i = 0; i < n / 2; i++)
        {
            const auto x = nums[i];
            const auto y = nums[n - i - 1];

            cnt[2] += 2;
            cnt[2 * limit + 1] -= 2;

            cnt[std::min(x + 1, y + 1)] -= 1;
            cnt[std::max(x + limit, y + limit) + 1] += 1;

            cnt[x + y] -= 1;
            cnt[x + y + 1] += 1;
        }

        auto r_sum = 0;
        auto res = n;

        for (auto i = 2; i <= 2 * limit; i++)
        {
            r_sum += cnt[i];
            res = std::min(res, r_sum);
        }

        return res;
    }
};