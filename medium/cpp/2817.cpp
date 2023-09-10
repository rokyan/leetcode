// https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/

class Solution
{
public:
    int minAbsoluteDifference(std::vector<int>& nums, int x)
    {
        std::set<int> s;

        auto res = -1;

        for (auto i = 0, j = x; j < std::size(nums); i++, j++)
        {
            s.insert(nums[i]);

            const auto it = s.lower_bound(nums[j]);

            if (it != std::end(s))
            {
                res = res == -1 ? *it - nums[j] : std::min(res, *it - nums[j]);
            }

            if (it != std::begin(s))
            {
                auto prev = it;
                std::advance(prev, -1);

                res = res == -1 ? nums[j] - *prev : std::min(res, nums[j] - *prev);
            }
        }

        return res;
    }
};