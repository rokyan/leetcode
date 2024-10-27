// https://leetcode.com/problems/minimum-number-of-increasing-subsequence-to-be-removed/description/

class Solution
{
private:
    static constexpr auto inf = 1000'000'000;

public:
    int minOperations(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        std::vector<int> dp(n + 1, -inf);
        dp[0] = inf;

        const auto comp = [](auto value, auto e)
        {
            return value > e;
        };

        for (auto i = 0; i < n; i++)
        {
            const auto pos = std::distance(
                std::cbegin(dp),
                std::upper_bound(std::cbegin(dp), std::cend(dp), nums[i], comp)
            );

            dp[pos] = nums[i];
        }

        return std::count_if(std::next(std::cbegin(dp)), std::cend(dp), [](auto e) {
            return e != -inf;
        });
    }
};