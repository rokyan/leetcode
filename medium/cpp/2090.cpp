// https://leetcode.com/problems/k-radius-subarray-averages/description/

class Solution
{
public:
    std::vector<int> getAverages(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> res(n, -1);

        const auto ws = 2 * k + 1;

        if (ws > n)
        {
            return res;
        }

        auto s = 0LL;

        for (auto i = 0; i < std::min<int>(n, ws); i++)
        {
            s += nums[i];
        }

        res[ws - k - 1] = s / ws;

        for (auto i = ws; i < n; i++)
        {
            s += nums[i] - nums[i - ws];
            res[i - k] = s / ws;
        }

        return res;
    }
};