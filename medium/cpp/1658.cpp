// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums, int x)
    {
        const auto n = std::size(nums);
        auto sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0);

        if (sum < x)
        {
            return -1;
        }

        const auto target = sum - x;
        auto len = -1;

        for (auto l = 0, r = 0, cur = 0; r < n; r++)
        {
            cur += nums[r];

            while (cur > target)
            {
                cur -= nums[l++];
            }

            if (cur == target)
            {
                len = std::max(len, r - l + 1);
            }
        }

        return len == -1 ? len : n - len;
    }
};