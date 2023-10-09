// https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/

class Solution
{
private:
    static constexpr auto mod = 1000000007;

public:
    int numberOfGoodSubarraySplits(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto last = 0;

        while (last < n && !nums[last])
        {
            last++;
        }

        if (last == n)
        {
            return 0;
        }

        auto res = 1;

        for (auto i = last + 1; i < n; i++)
        {
            if (nums[i])
            {
                res = 1LL * res * (i - last) % mod;
                last = i;
            }
        }

        return res;
    }
};