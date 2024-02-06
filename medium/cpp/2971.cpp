// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/

class Solution
{
public:
    long long largestPerimeter(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));

        auto res = -1LL;
        auto s = static_cast<long long>(nums[0] + nums[1]);

        for (auto i = 2; i < std::size(nums); i++)
        {
            if (nums[i] < s)
            {
                res = s + nums[i];
            }

            s += nums[i];
        }

        return res;
    }
};