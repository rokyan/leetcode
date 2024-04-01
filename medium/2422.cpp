// https://leetcode.com/problems/merge-operations-to-turn-array-into-a-palindrome/description/

class Solution
{
public:
    int minimumOperations(std::vector<int>& nums)
    {
        auto l = 0;
        auto r = static_cast<int>(std::size(nums)) - 1;

        auto lv = static_cast<long long>(nums[l]);
        auto rv = static_cast<long long>(nums[r]);

        auto res = 0;

        while (l < r)
        {
            if (lv == rv)
            {
                lv = nums[++l];
                rv = nums[--r];
            }
            else if (lv > rv)
            {
                rv += nums[--r];
                res++;
            }
            else
            {
                lv += nums[++l];
                res++;
            }
        }

        return res;
    }
};