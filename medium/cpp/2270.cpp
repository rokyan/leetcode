// https://leetcode.com/problems/number-of-ways-to-split-array/description/

class Solution
{
public:
    int waysToSplitArray(std::vector<int>& nums)
    {
        auto sum = std::accumulate(std::begin(nums), std::end(nums), 0LL);

        auto res = 0;
        auto cur = 0LL;

        for (auto i = 0; i + 1 < std::size(nums); i++)
        {
            cur += nums[i];
            sum -= nums[i];

            if (cur >= sum)
            {
                res++;
            }
        }

        return res;
    }
};