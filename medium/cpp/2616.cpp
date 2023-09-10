// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

class Solution
{
public:
    int minimizeMax(std::vector<int>& nums, int p)
    {
        std::sort(std::begin(nums), std::end(nums));

        auto lo = 0;
        auto hi = nums.back() - nums.front();

        while (lo < hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            auto cnt = 0;

            for (auto i = 1; i < std::size(nums) && cnt < p; i++)
            {
                if (nums[i] - nums[i - 1] <= mid)
                {
                    cnt++;
                    i++;
                }
            }

            if (cnt == p)
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