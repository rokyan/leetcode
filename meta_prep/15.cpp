#include <ranges>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        const int n = std::size(nums);

        std::ranges::sort(nums);

        std::vector<std::vector<int>> res;

        for (auto i = 0; i + 2 < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            const auto s = -nums[i];

            auto left = i + 1;
            auto right = n - 1;

            while (left < right)
            {
                if (left > i + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                }
                else if (right + 1 < n && nums[right] == nums[right + 1])
                {
                    right--;
                }
                else if (nums[left] + nums[right] < s)
                {
                    left++;
                }
                else if (nums[left] + nums[right] > s)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }

        return res;
    }
};