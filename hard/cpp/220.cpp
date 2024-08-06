// https://leetcode.com/problems/contains-duplicate-iii/description

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff)
    {
        std::multiset<int> values;

        for (auto i = 0; i < std::size(nums); i++)
        {
            const auto it = values.insert(nums[i]);

            if (it != std::begin(values) && nums[i] - *std::prev(it) <= valueDiff)
            {
                return true;
            }

            if (std::next(it) != std::end(values) && *std::next(it) - nums[i] <= valueDiff)
            {
                return true;
            }

            if (i >= indexDiff)
            {
                values.erase(values.find(nums[i - indexDiff]));
            }
        }

        return false;
    }
};