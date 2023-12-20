// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/

class Solution
{
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k)
    {
        if (std::size(nums) % 3 != 0)
        {
            return {};
        }

        std::sort(std::begin(nums), std::end(nums));

        std::vector<std::vector<int>> res;

        for (auto i = 0; i < std::size(nums); i += 3)
        {
            std::vector<int> cur { nums[i], nums[i + 1], nums[i + 2] };

            if (std::abs(cur[0] - cur[1]) > k || std::abs(cur[0] - cur[2]) > k ||
                std::abs(cur[1] - cur[2]) > k)
            {
                return {};
            }

            res.emplace_back(cur);
        }

        return res;
    }
};