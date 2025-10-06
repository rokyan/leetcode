class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> val_to_pos;

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (const auto it = val_to_pos.find(target - nums[i]);
                it != std::cend(val_to_pos))
            {
                return {it->second, i};
            }

            val_to_pos[nums[i]] = i;
        }

        return {};
    }
};