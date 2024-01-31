// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution
{
public:
    int maxFrequency(std::vector<int>& nums, int k)
    {
        std::sort(std::begin(nums), std::end(nums));

        const auto n = std::size(nums);

        auto res = 0;
        auto s = 0LL;

        for (auto l = 0, r = 0; r < n; r++)
        {
            s += nums[r];
            auto cur = 1LL * (r - l + 1) * nums[r] - s;

            while (cur > k)
            {
                s -= nums[l];
                cur -= (nums[r] - nums[l++]);
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};