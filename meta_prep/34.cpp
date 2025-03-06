class Solution
{
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target)
    {
        const auto first = find_first(nums, target);

        if (first == -1)
        {
            return {-1, -1};
        }

        return {first, find_last(nums, target)};
    }

private:
    int find_first(const std::vector<int>& nums, int target)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(nums)) - 1;
        auto idx = -1;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (target <= nums[mid])
            {
                if (nums[mid] == target)
                {
                    idx = mid;
                }

                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return idx;
    }

    int find_last(const std::vector<int>& nums, int target)
    {
        auto lo = 0;
        auto hi = static_cast<int>(std::size(nums)) - 1;
        auto idx = -1;

        while (lo <= hi)
        {
            const auto mid = lo + (hi - lo) / 2;

            if (target >= nums[mid])
            {
                if (target == nums[mid])
                {
                    idx = mid;
                }

                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return idx;
    }
};