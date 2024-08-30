// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums)
    {
        auto flips = 0;

        for (auto num : nums)
        {
            auto real = num ^ (flips % 2);

            if (real == 0)
            {
                flips++;
            }
        }

        return flips;
    }
};