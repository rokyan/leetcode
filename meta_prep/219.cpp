class Solution
{
public:
    bool containsNearbyDuplicate(const std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> val_to_pos;

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (auto it = val_to_pos.find(nums[i]); it != std::end(val_to_pos))
            {
                if (i - it->second <= k)
                {
                    return true;
                }

                it->second = i;
            }
            else
            {
                val_to_pos.emplace(nums[i], i);
            }
        }

        return false;
    }
};