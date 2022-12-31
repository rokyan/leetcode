// https://leetcode.com/problems/replace-elements-in-an-array/description/

class Solution
{
public:
    std::vector<int> arrayChange(std::vector<int>& nums, std::vector<std::vector<int>>& operations)
    {
        std::unordered_map<int, int> num_to_pos;

        for (auto pos = 0; pos < std::size(nums); pos++)
        {
            num_to_pos[nums[pos]] = pos;
        }

        for (auto&& operation : operations)
        {
            const auto old = operation[0];
            const auto upd = operation[1];

            const auto it = num_to_pos.find(old);
            const auto pos = it->second;

            num_to_pos.erase(it);

            num_to_pos[upd] = pos;
        }

        std::vector<int> res(std::size(nums));

        for (auto&& entry : num_to_pos)
        {
            res[entry.second] = entry.first;
        }

        return res;
    }
};