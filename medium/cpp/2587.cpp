// https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/

class Solution
{
public:
    int maxScore(std::vector<int>& nums)
    {
        const auto piv = std::partition(std::begin(nums), std::end(nums), [](auto num) { 
            return num > 0;
        });

        std::sort(piv, std::end(nums), std::greater<>{});

        auto res = piv - std::begin(nums);
        auto sum = std::accumulate(std::begin(nums), piv, 0LL);

        for (auto it = piv; it != std::end(nums) && sum > 0; it++)
        {
            sum += *it;

            if (sum > 0)
            {
                res++;
            }
        }

        return res;
    }
};