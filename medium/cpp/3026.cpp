// https://leetcode.com/problems/maximum-good-subarray-sum/description/

class Solution
{
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k)
    {
        auto s = 0LL;
        auto res = std::optional<long long>{};
        std::unordered_map<int, long long> m;

        for (auto i = 0; i < std::size(nums); i++)
        {
            s += nums[i];

            if (const auto it = m.find(nums[i] + k); it != std::end(m))
            {
                res = res ? std::max(*res, s - it->second) : s - it->second;
            }

            if (const auto it = m.find(nums[i] - k); it != std::end(m))
            {
                res = res ? std::max(*res, s - it->second) : s - it->second;
            }

            if (auto it = m.find(nums[i]); it != std::end(m))
            {
                it->second = std::min(it->second, s - nums[i]);
            }
            else
            {
                m.emplace(nums[i], s - nums[i]);
            }
        }

        return res ? *res : 0;
    }
};