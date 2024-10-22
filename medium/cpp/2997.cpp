// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums, int k)
    {
        auto res = 0;

        for (auto bit = 0; bit < 32; bit++)
        {
            auto ones = 0;

            for (auto num : nums)
            {
                if (num & (1 << bit))
                {
                    ones++;
                }
            }

            if (k & (1 << bit))
            {
                res += ones % 2 == 0;
            }
            else
            {
                res += ones % 2 == 1;
            }
        }

        return res;
    }
};