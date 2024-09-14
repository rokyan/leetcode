// https://leetcode.com/problems/reach-end-of-array-with-max-score/description/

class Solution
{
public:
    long long findMaximumScore(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto res = 0LL;
        auto last = 0;

        for (auto i = 1; i < n; i++)
        {
            if (nums[i] > nums[last])
            {
                res += 1LL * (i - last) * nums[last];
                last = i;
            }
        }

        if (last < n - 1)
        {
            res += 1LL * (n - 1 - last) * nums[last];
        }

        return res;
    }
};