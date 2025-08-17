// https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'007;

public:
    int xorAfterQueries(std::vector<int>& nums, const std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(nums);

        for (const auto& query : queries)
        {
            const auto left = query[0];
            const auto right = query[1];
            const auto k = query[2];
            const auto value = query[3];

            for (auto i = left; i <= right; i += k)
            {
                nums[i] = 1LL * nums[i] * value % mod;
            }
        }

        return std::accumulate(std::cbegin(nums), std::cend(nums), 0, [](auto x, auto y) {
            return x ^ y;
        });
    }
};