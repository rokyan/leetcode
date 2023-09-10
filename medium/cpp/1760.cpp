// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/

class Solution
{
public:
    int minimumSize(std::vector<int>& nums, int maxOperations)
    {
        auto lo = 1;
        auto hi = *std::max_element(std::cbegin(nums), std::cend(nums));

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto cnt = 0;

            for (auto num : nums)
            {
                cnt += (num - 1) / mid;

                if (cnt > maxOperations)
                {
                    break;
                }
            }

            if (cnt > maxOperations)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        return lo;
    }
};