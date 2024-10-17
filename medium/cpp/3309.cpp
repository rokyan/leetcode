// https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/

class Solution
{
public:
    int maxGoodNumber(std::vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));

        auto res = 0;

        do
        {
            res = std::max(res, count(nums));
        }
        while (std::next_permutation(std::begin(nums), std::end(nums)));

        return res;
    }

private:
    int count(const std::vector<int>& nums)
    {
        auto res = 0;
        auto bit = 0;

        for (auto num : nums)
        {
            while (num)
            {
                if (num & 1)
                {
                    res += 1 << bit;
                }

                num >>= 1;
                bit++;
            }
        }

        return res;
    }
};