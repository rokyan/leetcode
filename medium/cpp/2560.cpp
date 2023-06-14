// https://leetcode.com/problems/house-robber-iv/description/

class Solution
{
public:
    int minCapability(std::vector<int>& nums, int k)
    {
        auto lo = *std::min_element(std::begin(nums), std::end(nums));
        auto hi = *std::max_element(std::begin(nums), std::end(nums));

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto last = -2;
            auto cnt = 0;

            for (auto i = 0; i < std::size(nums) && cnt < k; i++)
            {
                if (nums[i] <= mid && i - last > 1)
                {
                    cnt++;
                    last = i;
                }
            }

            if (cnt == k)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }
};