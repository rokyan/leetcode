// https://leetcode.com/problems/maximum-sum-score-of-array/description/

class Solution
{
public:
    long long maximumSumScore(std::vector<int>& nums)
    {
        auto ls = 0LL;
        auto rs = std::accumulate(std::cbegin(nums), std::cend(nums), 0LL);
        auto res = std::max<long long>(nums[0], rs);

        for (auto i = 0; i < std::size(nums); i++)
        {
            ls += nums[i];
            res = std::max(res, std::max(ls, rs));
            rs -= nums[i];
        }

        return res;
    }
};