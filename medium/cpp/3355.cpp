// https://leetcode.com/problems/zero-array-transformation-i/description/

class Solution
{
public:
    bool isZeroArray(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries)
    {
        const auto n = std::size(nums);

        std::vector<int> acc(n + 1);

        for (const auto& query : queries)
        {
            const auto l = query[0];
            const auto r = query[1];
            acc[l]++;
            acc[r + 1]--;
        }

        for (auto i = 0, cur = 0; i < n; i++)
        {
            cur += acc[i];

            if (cur < nums[i])
            {
                return false;
            }
        }

        return true;
    }
};