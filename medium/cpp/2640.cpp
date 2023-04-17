// https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/

class Solution
{
public:
    std::vector<long long> findPrefixScore(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<long long> res(n);

        for (auto i = 0, mv = 0; i < n; i++)
        {
            mv = std::max(mv, nums[i]);
            res[i] = nums[i] + mv;
        }

        std::partial_sum(std::begin(res), std::end(res), std::begin(res));

        return res;
    }
};