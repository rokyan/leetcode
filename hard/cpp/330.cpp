// https://leetcode.com/problems/patching-array/description/

class Solution
{
public:
    int minPatches(const std::vector<int>& nums, int n)
    {
        auto last = 0LL;
        auto res = 0;

        for (auto i = 0; i < std::size(nums) && last < n; i++)
        {
            while (last < nums[i] - 1 && last < n)
            {
                res++;
                last = 2 * last + 1;
            }

            if (last == nums[i] - 1)
            {
                last = 2 * (nums[i] - 1) + 1;
            }
            else
            {
                last += nums[i];
            }
        }

        while (last < n)
        {
            res++;
            last = 2 * last + 1;
        }

        return res;
    }
};