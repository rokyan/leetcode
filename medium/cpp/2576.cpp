// https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/

class Solution
{
public:
    int maxNumOfMarkedIndices(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));

        const auto n = static_cast<int>(std::size(nums));

        auto res = 0;

        for (auto l = 0, r = n / 2; l < n / 2 && r < n; )
        {
            if (nums[l] * 2 <= nums[r])
            {
                l++;
                r++;
                res += 2;
            }
            else
            {
                r++;
            }
        }

        return res;
    }
};