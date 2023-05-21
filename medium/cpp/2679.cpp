// https://leetcode.com/problems/sum-in-a-matrix/description/

class Solution
{
public:
    int matrixSum(std::vector<std::vector<int>>& nums)
    {
        for (auto& row : nums)
        {
            std::sort(std::begin(row), std::end(row), std::greater<>{});
        }

        const auto n = std::size(nums);
        const auto m = std::size(nums.front());

        auto res = 0;

        for (auto j = 0; j < m; j++)
        {
            auto val = nums[0][j];

            for (auto i = 1; i < n; i++)
            {
                val = std::max(val, nums[i][j]);
            }

            res += val;
        }

        return res;
    }
};