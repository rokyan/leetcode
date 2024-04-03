// https://leetcode.com/problems/3sum-smaller/description/

class Solution
{
public:
    int threeSumSmaller(std::vector<int>& nums, int target)
    {
        std::sort(std::begin(nums), std::end(nums));

        const auto n = static_cast<int>(std::size(nums));

        auto res = 0;

        for (auto i = 0; i + 2 < n; i++)
        {
            const auto val = target - nums[i];

            auto j = i + 1;
            auto k = n - 1;

            while (j < k)
            {
                while (j < k && nums[j] + nums[k] >= val)
                {
                    k--;
                }

                if (j < k)
                {
                    res += k - j;
                }

                j++;
            }
        }

        return res;
    }
};