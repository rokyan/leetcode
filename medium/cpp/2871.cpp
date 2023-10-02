// https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/

class Solution
{
public:
    int maxSubarrays(std::vector<int>& nums)
    {
        auto val = nums.front();

        for (auto i = 1; i < std::size(nums); i++)
        {
            val &= nums[i];
        }

        if (val != 0)
        {
            return 1;
        }

        auto cur = -1;
        auto res = 0;

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (cur == -1)
            {
                cur = nums[i];

                if (cur == 0)
                {
                    cur = -1;
                    res++;
                }
            }
            else
            {
                cur &= nums[i];

                if (cur == 0)
                {
                    res++;
                    cur = -1;
                }
            }
        }

        return res;
    }
};