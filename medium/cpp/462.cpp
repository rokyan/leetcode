// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution
{
public:
    int minMoves2(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));

        const auto n = std::size(nums);

        auto pref = 0LL;
        auto suff = std::accumulate(std::cbegin(nums), std::cend(nums), 0LL);

        auto res = -1LL;

        for (auto i = 0; i < n; i++)
        {
            suff -= nums[i];

            const auto val = 1LL * i * nums[i] - pref + suff - 1LL * (n - i - 1) * nums[i];
            res = res == -1 ? val : std::min<long long>(val, res);

            pref += nums[i];
        }

        return res;
    }
};