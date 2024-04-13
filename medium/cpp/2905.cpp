// https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/description/

class Solution
{
public:
    std::vector<int> findIndices(std::vector<int>& nums, int indexDifference, int valueDifference)
    {
        const auto n = std::size(nums);

        std::multiset<std::pair<int, int>> suff;

        for (auto i = indexDifference; i < n; i++)
        {
            suff.insert({ nums[i], i });
        }

        auto min_value = nums[0];
        auto max_value = nums[0];
        auto min_idx = 0;
        auto max_idx = 0;

        for (auto i = 0; i + indexDifference < std::size(nums); i++)
        {
            if (nums[i] < min_value)
            {
                min_value = nums[i];
                min_idx = i;
            }

            if (nums[i] > max_value)
            {
                max_value = nums[i];
                max_idx = i;
            }

            if (std::abs(min_value - std::rbegin(suff)->first) >= valueDifference)
            {
                return { min_idx, std::rbegin(suff)->second };
            }

            if (std::abs(max_value - std::begin(suff)->first) >= valueDifference)
            {
                return { max_idx, std::begin(suff)->second };
            }

            suff.erase(suff.find({ nums[i + indexDifference], i + indexDifference }));
        }

        return { -1, -1 };
    }
};