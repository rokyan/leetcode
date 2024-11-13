// https://leetcode.com/problems/minimum-division-operations-to-make-array-non-decreasing/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));
        auto prev = nums[n - 1];
        auto res = 0;

        for (auto i = n - 2; i >= 0; i--)
        {
            auto cur = nums[i];

            while (cur > prev)
            {
                auto largest = 1;

                for (auto i = 2; i * i <= cur; i++)
                {
                    if (cur % i == 0)
                    {
                        largest = std::max({largest, i, cur / i});
                    }
                }

                if (largest == 1)
                {
                    break;
                }

                cur /= largest;
                res++;
            }

            if (cur > prev)
            {
                return -1;
            }

            prev = cur;
        }

        return res;
    }
};