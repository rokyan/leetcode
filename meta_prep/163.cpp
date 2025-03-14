class Solution
{
public:
    std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper)
    {
        const auto n = std::size(nums);

        if (n == 0)
        {
            std::vector<std::vector<int>> res;
            res.push_back({lower, upper});
            return res;
        }

        std::vector<std::vector<int>> res;
        res.reserve(n);

        if (lower < nums[0])
        {
            res.push_back({lower, nums[0] - 1});
        }

        for (auto i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1] + 1)
            {
                res.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }

        if (upper > nums[n - 1])
        {
            res.push_back({nums[n - 1] + 1, upper});
        }

        return res;
    }
};