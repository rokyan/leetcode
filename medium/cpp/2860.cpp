// https://leetcode.com/problems/happy-students/description/

class Solution
{
public:
    int countWays(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::sort(std::begin(nums), std::end(nums));

        auto res = 0;

        if (nums[0] > 0)
        {
            res++;
        }

        for (auto i = 0, c = 1; i < n; i++, c++)
        {
            if (c > nums[i] && (i == n - 1 || c < nums[i + 1]))
            {
                res++;
            }
        }

        return res;
    }
};