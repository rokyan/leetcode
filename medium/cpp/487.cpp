// https://leetcode.com/problems/max-consecutive-ones-ii/description/

class Solution
{
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums)
    {
        auto flipped = 0;
        auto res = 0;

        for (auto r = 0, l = 0; r < std::size(nums); r++)
        {
            if (nums[r] == 0)
            {
                flipped++;
            }

            while (flipped > 1)
            {
                if (nums[l++] == 0)
                {
                    flipped--;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};